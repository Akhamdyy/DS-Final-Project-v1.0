#pragma once
#include"AM.h"
class ArrayPointers
{
private:
	int count = 0;
	AM* arr = new AM[count];
public:
	ArrayPointers();
	int getcount();
	void setcount(int n);
	void add(AM t);
	void remove(AM& m);
	void print();
	bool IsEmpty();
};

