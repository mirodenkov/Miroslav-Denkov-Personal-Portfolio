#include "MyStack.h"
#include <cstdlib>
#include <cstring>
/* The stack is an abstract data type.
 * this means that the internal structures are
 * never exposed to the users of the library.
 */

/* Note: the stacks have no knowledge of what types
 * they are storing. This is not a concern of the stack
 */

MyStack::MyStack(std::size_t objsize)
{
	objSize = objsize;
	top = nullptr;
	numElem = 0;
}

int MyStack::myStackPush(void *obj)
{
	if (obj == nullptr)
		return -1;

	MyStackObject *newObj = new MyStackObject(obj, objSize);
	top = newObj; // put object on top (follow FIFO)
	numElem++;

	return 0;
}

int MyStack::myStackPop(void *obj)
{
	if (top == nullptr || obj == nullptr)
		return -1;

	std::memcpy(obj, top->getObject(), objSize);
	MyStackObject *temp = top;
	top = top->getNext();
	delete temp;
	numElem--;
	return 0;
}

MyStack::~MyStack()
{

	while (top != nullptr)
	{
		MyStackObject *temp = top;
		top = top->getNext();
		delete temp;
	}

	numElem = 0;
}

std::size_t MyStack::myStackNoOfElem()
{
	return numElem;
}
