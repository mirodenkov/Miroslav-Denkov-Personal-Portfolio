#include "Node.h"
using namespace std;

Node::Node(int value) : Node(value, nullptr) {} //constructor with nullptr
Node::Node(int value, Node* next) : value(value), next(next) {} //constructor with next ptr

int Node ::getValue() const
{
    return value;
}

Node* Node::getNext() const
{
    return next;
}

void Node::setValue(int val)
{
    this->value = val;
}

void Node::setNext(Node *next)
{
    this->next = next;
}