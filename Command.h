#pragma once
#include "URMprogram.h"
class Command : public URMprogram::CodeLine
{
public:
	Command(URMprogram& _pr);
	~Command();
	virtual void execute() = 0;
	virtual void print() = 0;
	static Command* cmdFactory(URMprogram& pr, std::string str);
};

