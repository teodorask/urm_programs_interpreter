#include "Command.h"
#include "Commands.h"
#include <sstream>
#include<cassert>

Command::Command(URMprogram& _pr) : URMprogram::CodeLine(_pr, "Cmd")
{
}


Command::~Command()
{
}

Command * Command::cmdFactory(URMprogram& pr, std::string str)
{
	std::istringstream iss(str);
	std::string type;
	iss >> type;
	Command* new_cmd = nullptr;
	if (type == "/zero")
	{
		int x, y;
		iss >> x >> y;
		new_cmd = new ZeroCmd(pr, x, y);
	}
	if (type == "/set")
	{
		int x, y;
		iss >> x >> y;
		new_cmd = new SetCmd(pr, x, y);
	}
	if (type == "/copy")
	{
		int x, y, z;
		iss >> x >> y >> z;
		new_cmd = new CopyCmd(pr, x, y, z);
	}
	if (type == "/mem")
	{
		int x, y;
		iss >> x >> y;
		new_cmd = new MemCmd(pr, x, y);
	}
	if (type == "/load")
	{
		std::string myfile;
		iss >> myfile;
		new_cmd = new LoadCmd(pr, myfile);
	}
	if (type == "/run")
	{
		new_cmd = new RunCmd(pr);
	}
	if (type == "/add")
	{
		std::string myfile;
		iss >> myfile;
		new_cmd = new AddCmd(pr, myfile);
	}
	if (type == "/quote")
	{
		std::string str;
		while (iss.peek() == ' ')
		{
			iss.get();
		}
		getline(iss, str);
		new_cmd = new QuoteCmd(pr, str);
	}
	if (type == "/code")
	{
		new_cmd = new CodeCmd(pr);
	}
	if (type == "/comment")
	{
		std::string str;
		iss >> str;
		new_cmd = new CommentCmd(pr, str);
	}
	if (new_cmd == nullptr) std::cout << "Invalid Command! Please try again! \n";
	assert(new_cmd != nullptr);
	return new_cmd;
}
