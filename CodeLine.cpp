#include "URMprogram.h"



URMprogram::CodeLine::CodeLine(URMprogram& _pr, std::string _type) : pr(_pr), type(_type)
{
}


URMprogram::CodeLine::~CodeLine()
{
}

std::string URMprogram::CodeLine::get_type() const
{
	return type;
}
