#include <cstdlib>
#include <cstring>
#include <exception>
using namespace std;

#include "MyStackObject.h"

MyStackObject::MyStackObject() : obj(nullptr), next(nullptr) {}

MyStackObject::MyStackObject(void *obj, size_t objSize) : MyStackObject()
{
	copyObject(obj, objSize);
}

MyStackObject::MyStackObject(void *obj, size_t objSize, MyStackObject *next) : next(next)
{
	copyObject(obj, objSize);
}

MyStackObject::~MyStackObject()
{
	// TODO: please implement this method
	delete[] static_cast<char *>(obj);
}

void MyStackObject::copyObject(void *obj, size_t objSize)
{
	// TODO: please implment this method. Don't use malloc, but new!!
	//  no throw std::bad_alloc() here. Because when new fails, it will throw bad_alloc automatically
	this->obj = new char[objSize];
	std::memcpy(this->obj, obj, objSize);
}

void *MyStackObject::getObject()
{
	return obj;
}

void MyStackObject::setNext(MyStackObject *next)
{
	this->next = next;
}

MyStackObject *MyStackObject::getNext()
{
	return next;
}