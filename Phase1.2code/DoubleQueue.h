#pragma once
#include <iostream>
#include "Node.h"
#include "QueueADT.h"
using namespace std;
/*
This is a program that implements the queue abstract data type using a linked list.
The queue is implemented as a chain of linked nodes that has two pointers,
a frontPtr pointer for the front of the queue and a backPtr pointer for the back of the queue.
*/

/*

				The Node: item of type T and a "next" pointer
					-------------
					| item| next | --->
					-------------
General Queue case:

				 frontPtr																backPtr
					\											   						/
					 \											  					   /
					------------- 	  ------------- 	  ------------- 	  -------------
					| item| next |--->| item| next |--->  | item| next |--->  | item| next |---> NULL
					------------- 	  ------------- 	  ------------- 	  -------------

Empty Case:

				 frontptr	 backptr
						\	 /
						 \	/
					---- NULL ------


Single Node Case:
				 frontPtr	 backPtr
					\		/
					 \	   /
					-----------
					|item| next| -->NULL
					-----------

*/

#ifndef DOUBLE_QUEUE_
#define DOUBLE_QUEUE_




template <typename T>
class DoubleQueue :public QueueADT<T>
{
private:
	Node<T>* backPtr;
	Node<T>* frontPtr;
	int count = 0;

public:
	DoubleQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntentry);
	bool Doubledequeue(T& frntentry, T& backentry);
	bool backdequeue(T& entry);
	bool peek(T& frntEntry)  const;
	int getcount();
	void print();
	~DoubleQueue();
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <typename T>
DoubleQueue<T>::DoubleQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;
	count = 0;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool DoubleQueue<T>::isEmpty() const
{
	if (frontPtr == NULL)
	{
		return true;
	}
	else { return false; }
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool DoubleQueue<T>::enqueue(const T& newEntry)
{
	count++;
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
		frontPtr = newNodePtr; // The queue is empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty

	backPtr = newNodePtr; // New node is the last node now
	
	return true;
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool DoubleQueue<T>::dequeue(T& frntEntry) {
	if (isEmpty())
		return false;
	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr;
	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;
	
	return true;
}
template <typename T>
//bool DoubleQueue<T>::Doubledequeue(T& frntentry, T& backentry)
//{
//	if (isEmpty())
//		return false;
//	if (frontPtr == backPtr) {
//		frntentry = frontPtr->getItem();
//		Node<T>* nodetodeleteptr = frontPtr;
//		backentry = frntentry;
//		frontPtr = NULL;
//		backPtr = NULL;
//		delete nodetodeleteptr;
//	}
//	else {
//
//		Node<T>* nodeToDeletePtr1 = frontPtr;
//		Node<T>* nodeToDeletePtr2 = frontPtr;
//		while (nodeToDeletePtr2->getNext()->getNext() != NULL) {
//			nodeToDeletePtr2 = nodeToDeletePtr2->getNext();
//		}
//		backentry = backPtr->getItem();
//		backPtr = nodeToDeletePtr2;
//		backPtr->setNext(NULL);
//		frntentry = frontPtr->getItem();
//		frontPtr = frontPtr->getNext();
//		nodeToDeletePtr1->setNext(NULL);
//		delete nodeToDeletePtr1;
//		delete nodeToDeletePtr2;
//	}
//	count = count - 2;
//	return true;
//
//
//}
//bool DoubleQueue<T>::Doubledequeue(T& frntentry, T& backentry)
//{
//	if (isEmpty() || count < 2)
//		return false;
//
//	Node<T>* nodeToDeletePtr1 = frontPtr;
//	Node<T>* nodeToDeletePtr2 = frontPtr;
//
//	// Move nodeToDeletePtr2 to the second-to-last node
//	while (nodeToDeletePtr2->getNext()->getNext() != NULL) {
//		nodeToDeletePtr2 = nodeToDeletePtr2->getNext();
//	}
//
//	// Save the front and back entries
//	frntentry = frontPtr->getItem();
//	backentry = nodeToDeletePtr2->getNext()->getItem();
//
//	// Update the front and back pointers
//	frontPtr = frontPtr->getNext();
//	backPtr = nodeToDeletePtr2;
//
//	// Delete the first and second nodes
//	nodeToDeletePtr1->setNext(NULL);
//	delete nodeToDeletePtr1;
//	nodeToDeletePtr2->setNext(NULL);
//	delete nodeToDeletePtr2->getNext();
//
//	count -= 2;
//	return true;
//}
bool DoubleQueue<T>::Doubledequeue(T& frntentry, T& backentry)
{
	//if (isEmpty())
	//	return false;

	//Node<T>* nodeToDeletePtr1 = frontPtr;
	//Node<T>* nodeToDeletePtr2 = frontPtr;

	//// Move nodeToDeletePtr2 to the last node
	//while (nodeToDeletePtr2->getNext() != NULL) {
	//	nodeToDeletePtr2 = nodeToDeletePtr2->getNext();
	//}

	//// Save the front and back entries
	//frntentry = frontPtr->getItem();
	//backentry = nodeToDeletePtr2->getItem();

	//// Update the front and back pointers
	//if (count > 1) {
	//	frontPtr = frontPtr->getNext();
	//	backPtr = nodeToDeletePtr2->getNext();
	//}
	//else {
	//	frontPtr = nullptr;
	//	backPtr = nullptr;
	//}

	//// Delete the first and last nodes
	//nodeToDeletePtr1->setNext(NULL);
	///*delete nodeToDeletePtr1;*/
	//nodeToDeletePtr2->setNext(NULL);
	///*delete nodeToDeletePtr2;*/

	//if (count <=2 )
	//{
	//	count = 0;
	//}
	//else
	//{
	//	count = count - 2;
	//}
	//return true;
	if (isEmpty())
	{
		return false;
	}
	else if (count<2)
	{
		return false;
	}
	else
	{
		dequeue(frntentry);
		backdequeue(backentry);
		count = count - 2;

	}

}

template<typename T>
inline bool DoubleQueue<T>::backdequeue(T& entry)
{
	/*if (isEmpty())
	{
		return false;
	}*/
	Node<T>* nodetodelete = backPtr;
	entry = nodetodelete->getItem(); // Save the item to be returned

	if (frontPtr == backPtr)
	{
		delete nodetodelete;
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
		delete nodetodelete;
		backPtr = prevNode;
	}

	
	return true;
}


/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peek
copies the front of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
*/

template <typename T>
bool DoubleQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
DoubleQueue<T>::~DoubleQueue()
{
	//Note that the cout statements here is just for learning purpose
	//They should be normally removed from the destructor
	cout << "\nStarting LinkedQueue destructor...";
	cout << "\nFreeing all nodes in the queue...";

	//Free all nodes in the queue
	T temp;
	while (dequeue(temp));

	cout << "\n Is LinkedQueue Empty now?? ==> " << boolalpha << isEmpty();
	cout << "\nEnding LinkedQueue destructor..." << endl;
}
template<typename T>
void DoubleQueue<T>::print()
{
	Node<T>* ptr = frontPtr;
	while (ptr != NULL)
	{
		cout << ptr->getItem()->getid() << ", ";
		ptr = ptr->getNext();
	}
}
template<typename T>
int DoubleQueue<T>::getcount()
{
	if (count < 0)
	{
		return 0;
	}
	return count;	
}

#endif