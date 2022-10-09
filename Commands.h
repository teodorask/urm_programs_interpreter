#pragma once
#include "Command.h"

class ZeroCmd : public Command
{
public:
	ZeroCmd(URMprogram& pr, int _x, int _y);
	~ZeroCmd();
	void execute();
	void print();
private:
	int x, y;
};

class SetCmd : public Command
{
public:
	SetCmd(URMprogram& pr, int _x, int _y);
	~SetCmd();
	void execute();
	void print();
private:
	int x, y;
};

class CopyCmd : public Command
{
public:
	CopyCmd(URMprogram& pr, int _x, int _y, int _z);
	~CopyCmd();
	void execute();
	void print();
private:
	int x, y, z;
};

class MemCmd : public Command
{
public:
	MemCmd(URMprogram& pr, int _x, int _y);
	~MemCmd();
	void execute();
	void print();
private:
	int x, y;
};

class LoadCmd : public Command
{
public:
	LoadCmd(URMprogram& pr, std::string _myfile);
	~LoadCmd();
	void execute();
	void print();
private:
	std::string myfile;
};

class RunCmd : public Command
{
public: 
	RunCmd(URMprogram& pr);
	~RunCmd();
	void execute();
	void print();
};

class AddCmd : public Command
{
public:
	AddCmd(URMprogram& pr, std::string _new_file);
	~AddCmd();
	void execute();
	void print();
private:
	std::string new_file;
};

class QuoteCmd : public Command
{
public:
	QuoteCmd(URMprogram& pr, std::string _str);
	~QuoteCmd();
	void execute();
	void print();
private:
	std::string str;
};

class CodeCmd : public Command
{
public:
	CodeCmd(URMprogram& pr);
	~CodeCmd();
	void execute();
	void print();
};

class CommentCmd : public Command
{
public:
	CommentCmd(URMprogram& pr, std::string _str);
	~CommentCmd();
	void execute();
	void print();
private:
	std::string str;
};