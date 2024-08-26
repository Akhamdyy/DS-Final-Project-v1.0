#include "ArrayPointers.h"

ArrayPointers::ArrayPointers()
{
	count = 1;
}

int ArrayPointers::getcount()
{
	return count;
}

void ArrayPointers::setcount(int n)
{
	count = n;
}

void ArrayPointers::add(AM t)
{
	arr[count] = t;
	count++;
}

void ArrayPointers::remove(AM& m)
{
	if (IsEmpty() == 1) {
		return;
	}
	else if (count == 0) {
		m = arr[count];
		arr = NULL;
	}
	else {
		for (int i = 0; i < count; i++) {
			if (m.getid() == arr[i].getid()) {
				arr[i] = arr[count];
				count--;
			}
		}
	}
}

void ArrayPointers::print()
{
	if (IsEmpty() == 1) {
		return;
	}
	else if (count == 0) {
		cout << arr[count].getid();
	}
	else {
		for (int i = 0; i < count; i++) {
			cout << arr[i].getid() << ", ";
		}
	}


		
}

bool ArrayPointers::IsEmpty()
{
	if (arr==nullptr) {
		return true;
	}
	return false;
}
