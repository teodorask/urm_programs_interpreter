#pragma once
#include "URMprogram.h"

class ZeroInstr : public URMprogram::Instruction
{
public:
	ZeroInstr(URMprogram& _pr ,size_t _line, int _x);
	~ZeroInstr();
	void execute();
	void print();
	void resize(int b, int N);
	int max_cell();
private:
	int x;
};

class IncInstr : public URMprogram::Instruction
{
public:
	IncInstr(URMprogram& _pr, size_t _line, int _x);
	~IncInstr();
	void execute();
	void print();
	void resize(int b, int N);
	int max_cell();
private:
	int x;
};

class MoveInstr : public URMprogram::Instruction
{
public:
	MoveInstr(URMprogram& _pr, size_t _line, int _x, int _y);
	~MoveInstr();
	void execute();
	void print();
	void resize(int b, int N);
	int max_cell();
private:
	int x, y;
};

class JumpInstr : public URMprogram::Instruction
{
public:
	JumpInstr(URMprogram& _pr, size_t _line, int _x, int _y, int _z);
	~JumpInstr();
	void execute();
	void print();
	void resize(int b, int N);
	int max_cell();
private:
	int x, y, z;
};