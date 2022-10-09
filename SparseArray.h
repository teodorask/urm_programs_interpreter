#pragma once
#include <unordered_map>
class sparseArray
{
public:
	sparseArray();
	~sparseArray();
	sparseArray(const sparseArray&);
	sparseArray& operator= (const sparseArray&);
	void setElement(size_t data, size_t index);
	int& operator[](size_t index);
	bool isDefined(size_t index);
	void deleteAll();
private:
	std::unordered_map<int, int> mem;
};

