#pragma once
#include <iostream>
#include "Node.h"
#include "QueueADT.h"
using namespace std;
template <typename T>
class DoubleListQueue:public QueueADT<T>
{
private:
	Node<T>* frontPtr;
	Node<T>* backPtr;
	int count;
public:
	DoubleListQueue()
	{
		frontPtr = nullptr;
		backPtr = nullptr;
		count = 0;
	}
	bool isEmpty() const
	{
		if (frontPtr == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool enqueue(const T& newEntry)
	{
		Node<T>* newNodePtr = new Node<T>(newEntry);
		if (isEmpty())
		{
			frontPtr = newNodePtr;
		}
		else
		{
			backPtr->setNext(newNodePtr);
		}
		count++;
		backPtr = newNodePtr;
		return true;
	}
	bool enqueuefront(const T& newEntry)
	{
		Node<T>* newNodeptr = new Node<T>(newEntry);
		if (isEmpty())
		{
			frontPtr = newNodeptr;
		}
		else
		{
			newNodeptr->setNext(frontPtr);
			frontPtr = newNodeptr;
		}
		count++;
		return true;
	}
	bool dequeue(T& frntentry)
	{
		if (isEmpty())
		{
			return false;
		}
		Node<T>* nodeToDeletePtr = frontPtr;
		frntentry = frontPtr->getItem();
		frontPtr = frontPtr->getNext();
		if (nodeToDeletePtr == backPtr)
		{
			backPtr = nullptr;
		}
		delete nodeToDeletePtr;
		count;
		return true;
	}
	bool dequeueback(T& backentry)
	{
		if (isEmpty())
		{
			return false;
		}
		Node<T>* nodetoDeletePtr = backPtr;
		backentry = nodetoDeletePtr->getItem();
		if (frontPtr == backPtr)
		{
			delete nodetoDeletePtr;
			frontPtr = backPtr = nullptr;
		}
		else
		{
			Node<T>* prevNode = frontPtr;
			while (prevNode->getNext() != backPtr)
			{
				prevNode = prevNode->getNext();
			}
			prevNode->setNext(nullptr);
			delete nodetoDeletePtr;
			backPtr = prevNode;
		}
	}
	bool Doubledequeue(T& frnt, T& back)
	{
		if (count < 2)
		{
			return false;
		}
		else
		{
			dequeue(frnt);
			dequeueback(back);
			count = count - 2;
			return true;
		}
	}
	bool peek(T& frntEntry) const
	{
		if (isEmpty())

		{
			return false;
		}
		frntEntry = frontPtr->getItem();
		return true;
	}
	void print()
	{
		Node<T>* ptr = frontPtr;
		while (ptr != NULL)
		{
			cout << ptr->getItem()->getid() << ", ";
			ptr = ptr->getNext();
		}
	}
	int getcount()
	{
		if (isEmpty())
		{
			return 0;
		}
		else
		{
			return this->count;
		}
	}

};

