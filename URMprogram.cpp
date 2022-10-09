#include "URMprogram.h"
#include "Instructions.h"
#include "Command.h"
#include <sstream>
#include <cassert>
#include <iostream>
#include <fstream>

URMprogram::URMprogram()
{
	current_instr = 0;
	current_line = 0;
}


URMprogram::~URMprogram()
{
}

URMprogram::Instruction::Instruction(URMprogram& _pr, size_t _line) : URMprogram::CodeLine(_pr, "Instr"), line(_line)
{
}

URMprogram::Instruction::~Instruction()
{
}

URMprogram::Instruction * URMprogram::Instruction::instrFactory(URMprogram& _pr, std::string str, int line)
{
	std::istringstream iss(str);
	std::string type;
	iss >> type;
	URMprogram::Instruction* new_instr = nullptr;
	if (type == "ZERO")
	{
		int x;
		iss >> x;
		new_instr = new ZeroInstr(_pr, line, x);
	}
	if (type == "INC")
	{
		int x;
		iss >> x;
		new_instr = new IncInstr(_pr, line, x);
	}
	if (type == "MOVE")
	{
		int x, y;
		iss >> x >> y;
		new_instr = new MoveInstr(_pr, line, x, y);
	}
	if (type == "JUMP")
	{
		int x[3] = { -1, -1, -1 };
		size_t i = 0;
		while (iss)
		{
			iss >> x[i++];
		}
		new_instr = new JumpInstr(_pr, line, x[0], x[1], x[2]);
	}
	assert(new_instr != nullptr);
	return new_instr;
}

int URMprogram::Instruction::get_line() const
{
	return line;
}


void URMprogram::zero(size_t x, size_t y)
{
	while (x <= y)
	{
		memory.setElement(0, x++);
	}
}

void URMprogram::set(size_t x, size_t y)
{
	memory.setElement(y, x);
}

void URMprogram::copy(size_t x, size_t y, size_t z)
{
	int* save;
	save = new int[z];
	for (size_t i = 0; i < z; i++)
	{
		save[i] = memory[x + i];
	}
	for (size_t i = 0; i < z; i++)
	{
		memory.setElement(save[i], y + i);
	}
}

void URMprogram::mem(size_t x, size_t y)
{
	while (x <= y)
	{
			std::cout << memory[x++] << " ";
	}
	std::cout << '\n';
}

void URMprogram::load(std::string myfile)
{
	std::ifstream indata(myfile);
	if (!indata)
	{
		std::cout << "couldn't open " << myfile << "\n";
	}
	else
	{
		memory.deleteAll();
		instr.clear();
		pr_code.clear();
		indata >> *this;
		std::cout << "successfully opened " << myfile << "\n";
	}
}

void URMprogram::add(std::string myfile)
{
	std::ifstream indata(myfile);
	int b = max_cell();
	int N = instr.size();
	indata >> *this;
	for (size_t i = N; i < instr.size(); i++)
	{
		instr[i]->resize(b, N);
	}
}

void URMprogram::quote(std::string str)
{
	if (str[0] == '/')
	{
		Command* new_cmd = Command::cmdFactory(*this, str);
		assert(new_cmd != nullptr);
		pr_code.push_back(new_cmd);
	}
	else
	{
		Instruction* new_instr = Instruction::instrFactory(*this, str, pr_code.size());
		pr_code.push_back(new_instr);
		instr.push_back(new_instr);
	}
}

void URMprogram::code()
{
	for (URMprogram::CodeLine* line : pr_code)
	{
		line->print();
		std::cout << '\n';
	}
}

void URMprogram::run()
{
	
	current_instr = 0;
	current_line = 0;
	std::cout << "running... ";
	while (current_instr < instr.size() && current_line < pr_code.size())
	{
		if (pr_code[current_line]->get_type() == "Cmd")
		{
			pr_code[current_line]->execute();
			current_line++;
		}
		else
		{
			instr[current_instr]->execute();
		}
	}
	std::cout << "done! \n";
}

int URMprogram::max_cell()
{
	int result = 0;
	for (Instruction* i : instr)
	{
		if (i->max_cell() > result) result = i->max_cell();
	}
	return result;
}

std::istream & operator>>(std::istream & in, URMprogram & pr)
{
	std::string new_line;
	while (getline(in, new_line))
	{
		if (new_line[0] == '/')
		{
			Command* new_cmd = Command::cmdFactory(pr, new_line);
			assert(new_cmd != nullptr);
			pr.pr_code.push_back(new_cmd);
		}
		else
		{
			URMprogram::Instruction* new_instr = URMprogram::Instruction::instrFactory(pr, new_line, pr.pr_code.size());
			pr.instr.push_back(new_instr);
			pr.pr_code.push_back(new_instr);
		}

	}
	return in;
}
