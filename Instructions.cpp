#include "Instructions.h"
#include <iostream>
#include <algorithm>

ZeroInstr::ZeroInstr(URMprogram& _pr, size_t _line, int _x) : URMprogram::Instruction(_pr, _line), x(_x)
{
}

ZeroInstr::~ZeroInstr()
{
}

void ZeroInstr::execute()
{
	pr.memory.setElement(0, x);
	pr.current_line++;
	pr.current_instr++;
}

void ZeroInstr::print()
{
	std::cout << "ZERO " << x;
}

void ZeroInstr::resize(int b, int N)
{
	x += b + 1;
}

int ZeroInstr::max_cell()
{
	return x;
}

IncInstr::IncInstr(URMprogram& _pr, size_t _line, int _x) : URMprogram::Instruction(_pr, _line), x(_x)
{
}

IncInstr::~IncInstr()
{
}

void IncInstr::execute()
{
	pr.memory[x]++;
	pr.current_line++;
	pr.current_instr++;
}

void IncInstr::print()
{
	std::cout << "INC " << x;
}

void IncInstr::resize(int b, int N)
{
	x += b + 1;
}

int IncInstr::max_cell()
{
	return x;
}

MoveInstr::MoveInstr(URMprogram& _pr, size_t _line, int _x, int _y) : URMprogram::Instruction(_pr, _line), x(_x), y(_y)
{
}

MoveInstr::~MoveInstr()
{
}

void MoveInstr::execute()
{
	pr.memory.setElement(pr.memory[x], y);
	pr.current_line++;
	pr.current_instr++;
}

void MoveInstr::print()
{
	std::cout << "MOVE " << x << " " << y;
}

void MoveInstr::resize(int b, int N)
{
	x += b + 1;
	y += b + 1;
}

int MoveInstr::max_cell()
{
	return std::max(x, y);
}

JumpInstr::JumpInstr(URMprogram& _pr, size_t _line, int _x, int _y, int _z) : URMprogram::Instruction(_pr, _line), x(_x), y(_y), z(_z)
{
}

JumpInstr::~JumpInstr()
{
}

void JumpInstr::execute()
{
	if (y == -1)
	{
		pr.current_instr = x;
		if (x < pr.instr.size()) pr.current_line = pr.instr[x]->get_line();
		else pr.current_line = pr.pr_code.size();
	}
	else if (pr.memory[x] == pr.memory[y])
	{
		pr.current_instr = z;
		if (z < pr.instr.size()) pr.current_line = pr.instr[z]->get_line();
		else pr.current_line = pr.pr_code.size();
	}
	else
	{
		pr.current_instr++;
		pr.current_line++;
	}
}

void JumpInstr::print()
{
	std::cout << "JUMP " << x;
	if (y != -1) std::cout << " " << y << " " << z;
}

void JumpInstr::resize(int b, int N)
{
	if (y == -1) x += N;
	else
	{
		x += b + 1;
		y += b + 1;
		z += N;
	}
}

int JumpInstr::max_cell()
{
	if (y == -1) return 0;
	return std::max(x, y);
}
