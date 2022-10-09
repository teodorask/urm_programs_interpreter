#include "Commands.h"
#include <iostream>

ZeroCmd::ZeroCmd(URMprogram& pr, int _x, int _y) : Command(pr), x(_x), y(_y)
{
}

ZeroCmd::~ZeroCmd()
{
}

void ZeroCmd::execute()
{
	pr.zero(x, y);
}

void ZeroCmd::print()
{
	std::cout << "/zero " << x << " " << y;
}

SetCmd::SetCmd(URMprogram& pr, int _x, int _y) : Command(pr), x(_x), y(_y)
{
}

SetCmd::~SetCmd()
{
}

void SetCmd::execute()
{
	pr.set(x, y);
}

void SetCmd::print()
{
	std::cout << "/set " << x << " " << y;
}

CopyCmd::CopyCmd(URMprogram& pr, int _x, int _y, int _z) : Command(pr), x(_x), y(_y), z(_z)
{
}

CopyCmd::~CopyCmd()
{
}

void CopyCmd::execute()
{
	pr.copy(x, y, z);
}

void CopyCmd::print()
{
	std::cout << "/copy " << x << " " << y << " " << z;
}

MemCmd::MemCmd(URMprogram& pr, int _x, int _y) : Command(pr), x(_x), y(_y)
{
}

MemCmd::~MemCmd()
{
}

void MemCmd::execute()
{
	pr.mem(x, y);
}

void MemCmd::print()
{
	std::cout << "/mem " << x << " " << y;
}

LoadCmd::LoadCmd(URMprogram& pr, std::string _myfile) : Command(pr), myfile(_myfile)
{
}

LoadCmd::~LoadCmd()
{
}

void LoadCmd::execute()
{
	pr.load(myfile);
}


void LoadCmd::print()
{
	std::cout << "/load " << myfile;
}

RunCmd::RunCmd(URMprogram& pr) : Command(pr)
{
}

RunCmd::~RunCmd()
{
}

void RunCmd::execute()
{
	pr.run();
}

void RunCmd::print()
{
	std::cout << "/run ";
}

AddCmd::AddCmd(URMprogram& pr, std::string _new_file) : Command(pr), new_file(_new_file)
{
}

AddCmd::~AddCmd()
{
}

void AddCmd::execute()
{
	pr.add(new_file);
}

void AddCmd::print()
{
	std::cout << "/add " << new_file;
}

QuoteCmd::QuoteCmd(URMprogram& pr, std::string _str) : Command(pr), str(_str)
{
}

QuoteCmd::~QuoteCmd()
{
}

void QuoteCmd::execute()
{
	pr.quote(str);
}

void QuoteCmd::print()
{
	std::cout << "/quote " << str;
}

CodeCmd::CodeCmd(URMprogram& pr) : Command(pr)
{
}

CodeCmd::~CodeCmd()
{
}

void CodeCmd::execute()
{
	pr.code();
}

void CodeCmd::print()
{
	std::cout << "/code ";
}

CommentCmd::CommentCmd(URMprogram& pr, std::string _str) : Command(pr), str(_str)
{
}

CommentCmd::~CommentCmd()
{
}

void CommentCmd::execute()
{
}

void CommentCmd::print()
{
	std::cout << "/comment " << str;
}
