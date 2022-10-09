#include "SparseArray.h"
#include <iterator>


sparseArray::sparseArray()
{
}


sparseArray::~sparseArray()
{
}

sparseArray::sparseArray(const sparseArray& src)
{
	this->mem = src.mem;
}

sparseArray & sparseArray::operator=(const sparseArray &src)
{
	if (this != &src)
	{
		this->mem = src.mem;
	}
	return *this;
}

void sparseArray::setElement(size_t data, size_t index)
{
	mem[index] = data;
}

int & sparseArray::operator[](size_t index)
{
	return mem[index];
}

bool sparseArray::isDefined(size_t index)
{
	std::unordered_map<int, int>::iterator itr = mem.find(index);
	if (itr == mem.end()) return false;
	else return true;
}

void sparseArray::deleteAll()
{
	mem.clear();
}
