#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList
{
private:
    Node *head, *tail;

public:
    LinkedList();
    int addFirst(int value);
    int addLast(int value);
    int addAfter(Node *node, int value);
    int getHeadValue() const;
    Node *getHead() const;
    Node *getTail() const;
    int getTailValue() const;
    int getElementValue(int element_id) const;
    int remFirst();
    int remLast();
    int clean();
};

#endif