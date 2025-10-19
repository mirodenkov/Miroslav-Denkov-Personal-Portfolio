#include "MyStack.h"
#include "MyQueue.h"

MyQueue::MyQueue(std::size_t itemsize)
{
	this->itemSize = itemsize;
	this->stackIn = new MyStack(itemSize);
	this->stackOut = new MyStack(itemSize);
}

MyQueue::~MyQueue()
{
	delete stackIn;
	delete stackOut;
}

int MyQueue::myQueueEnqueue(void *obj)
{
	if (obj == nullptr)
	{
		return -1; // null pointer check
	}
	if (itemSize == 0)
	{
		return -1; // item size not set
	}
	if (stackIn->myStackPush(obj) != 0)
	{
		return -1;
	}
	return 0;
}

int MyQueue::myQueueDequeue(void *obj)
{
	if (obj == nullptr)
	{
		return -1;
	}
	char *temp = new char[itemSize];
	if (stackOut->myStackNoOfElem() == 0)
	{
		while (stackIn->myStackNoOfElem() != 0)
		{
			if (stackIn->myStackPop(temp) == 0)
			{
				stackOut->myStackPush(temp);
			}
			else
			{
				delete[] temp;
				return -1;
			}
		}
		delete[] temp;
	}
	stackOut->myStackPop(obj);
	return 0;
}
