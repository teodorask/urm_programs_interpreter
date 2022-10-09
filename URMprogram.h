#pragma once
#include "SparseArray.h"
#include <vector>
#include <string>
#include <iostream>

class URMprogram
{
public:
	URMprogram();
	~URMprogram();

	class CodeLine
	{
	public:
		CodeLine(URMprogram& _pr, std::string _type);
		~CodeLine();
		virtual void execute() = 0;
		virtual void print() = 0;
		std::string get_type() const;
	protected:
		URMprogram& pr;
		std::string type;
	};

	class Instruction : public URMprogram::CodeLine
	{
	public:
		Instruction(URMprogram& _pr, size_t _line);
		~Instruction();
		virtual void execute() = 0;
		virtual void print() = 0;
		virtual void resize(int b, int N) = 0;
		static Instruction* instrFactory(URMprogram& _pr,std::string str, int commands_index);
		virtual int max_cell() = 0;
		int get_line() const;
	protected:
		size_t line;
	};

	friend class ZeroInstr;
	friend class IncInstr;
	friend class MoveInstr;
	friend class JumpInstr;

	//sets cells x-y to 0
	void zero(size_t x, size_t y);
	//sets cell x to y
	void set(size_t x, size_t y);
	//copies z number of cells starting from x into z number of cells starting from y
	void copy(size_t x, size_t y, size_t z);
	//prints cells x-y
	void mem(size_t x, size_t y);
	//loads new urm program from file
	void load(std::string myfile);
	//appends operators from file to the current urm program 
	void add(std::string myfile);
	//appends new operator to the current program
	void quote(std::string);
	//prints the current program
	void code();
	//runs the current program
	void run();

	int max_cell();
	friend std::istream& operator>> (std::istream& in, URMprogram& pr);
private:
	sparseArray memory;
	std::vector<CodeLine*> pr_code;
	std::vector<Instruction*> instr;
	size_t current_line;
	size_t current_instr;
};

