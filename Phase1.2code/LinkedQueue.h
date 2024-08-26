
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

#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include"Unit.h"
#include "Node.h"
#include "QueueADT.h"

template <typename T>
class LinkedQueue :public QueueADT<T>
{
private:
	Node<T>* backPtr;
	Node<T>* frontPtr;
	int count = 0;
public:
	LinkedQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	int getcount();
	void print();
	void killprint();
	Node<T> getfront();
	~LinkedQueue();
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <typename T>
LinkedQueue<T>::LinkedQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool LinkedQueue<T>::isEmpty() const
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

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool LinkedQueue<T>::enqueue(const T& newEntry)
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


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool LinkedQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;
	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	if (nodeToDeletePtr == backPtr)	 
		backPtr = nullptr;
	delete nodeToDeletePtr;
	count--;
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
bool LinkedQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////
//void LinkedQueue<int>::Deletenegatives()
//{
//	Node<int>* ptr = frontPtr;
//	while (ptr->getNext()->getNext() != nullptr)
//	{
//		if (ptr->getNext()->getItem() < 0)
//		{
//			Node<int>* ptr1 = ptr->getNext();
//			ptr->setNext(ptr1->getNext());
//			ptr1->setNext(nullptr);
//			delete ptr1;
//		}
//		ptr = ptr->getNext();
//	}
//	if (ptr->getNext()->getItem() < 0)
//	{
//		Node<int>* ptr1 = ptr->getNext();
//		ptr->setNext(ptr1->getNext());
//		ptr1->setNext(nullptr);
//		delete ptr1;
//	}
//}
template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
	//Note that the cout statements here is just for learning purpose
	//They should be normally removed from the destructor
	//Free all nodes in the queue
	T temp;
	while (dequeue(temp));
}
	template<typename T>
	/*void LinkedQueue <T>::print()
	{
		Node<T>* ptr = frontPtr;
		while (ptr != NULL)
		{
			cout << ptr->getItem()->getid()<<", " << endl;
			ptr = ptr->getNext();
		}
	*/
	void LinkedQueue <T>::print()
	{
		Node<T>* ptr = frontPtr;
		while (ptr != nullptr)
		{
			cout << ptr->getItem()->getid()<<", ";
			ptr = ptr->getNext();
		}
	}
	template<typename T>
	inline void LinkedQueue<T>::killprint()
	{
		Node<T>* ptr = frontPtr;
		while (ptr != NULL)
		{

			cout << ptr->getItem() << ", ";
			ptr = ptr->getNext();
		}
	}
	/*void LinkedQueue<int>::print()
	{

		cout << "Count = " << count << endl;
		Node<int>* ptr = frontPtr;
		while (ptr != NULL)
		{
			cout << ptr->getItem()<< ", ";
			ptr = ptr->getNext();
		}
	}*/

template<typename T>
Node<T> LinkedQueue<T>::getfront()
{
	return frontPtr;
	
}
template<typename T>
int LinkedQueue<T>::getcount()
{
	if (isEmpty())
	{
		return 0;
	}
	else {
		return count;
	}
}

#endif
