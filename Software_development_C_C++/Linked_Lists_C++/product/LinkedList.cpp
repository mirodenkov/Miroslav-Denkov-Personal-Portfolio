#include "LinkedList.h"
using namespace std;

LinkedList ::LinkedList() : head(nullptr), tail(nullptr) {}

int LinkedList ::addFirst(int value)
{
    Node *node = new Node(value); // create a new node
    if (node == nullptr)
    {
        return -1;
    }

    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        node->setNext(head);
        head = node;
    }
    return 0;
}

int LinkedList ::addLast(int value)
{
    Node *node = new Node(value);
    node->setNext(nullptr); // new node’s next should start out null
    if (head == nullptr)
    {
        head = tail = node; // first element: head and tail are the same
    }
    else
    {
        tail->setNext(node); // link old tail → new node
        tail = node;         // update tail to the new node
    }
    return 0;
}

int LinkedList::addAfter(Node *node, int value)
{
    Node *new_node = new Node(value);
    if (node == nullptr)
    {
        return -1; // fail if node is a NULL ptr
    }
    Node *current = head;
    while (current != nullptr)
    {
        if (current == node)
        {
            new_node->setNext(node->getNext()); // new_node now points to the old node's NEXT
            node->setNext(new_node);
            return 1;
        }
        else
            current = current->getNext();
    }

    return -1;
}

int LinkedList::getHeadValue() const
{
    return head->getValue();
}

int LinkedList::getTailValue() const
{
    return tail->getValue();
}

int LinkedList::getElementValue(int element_id) const
{
    // Guard against empty list and negative index
    if (head == nullptr || element_id < 0)
    {
        return -1;
    }

    Node *temp = head;
    // Walk forward, but bail out if we hit nullptr before reaching element_id
    for (int i = 0; i < element_id; i++)
    {
        temp = temp->getNext();
        if (temp == nullptr)
        {
            return -1; // index out of bounds
        }
    }

    // temp now points to the desired node; just read its value
    return temp->getValue();
}

/*getter for head*/
Node *LinkedList::getHead() const
{
    return head;
}
Node *LinkedList::getTail() const
{
    return tail;
}
// deletes head
int LinkedList::remFirst()
{
    if (head == nullptr)
    {
        return -1;
    }

    Node *temp = head; // save the head in a temp node
    head = head->getNext();
    if (head == nullptr)
    {
        tail = nullptr;
    }

    delete temp;

    return 0;
}
int LinkedList::remLast()
{

    if (head == nullptr)
    {
        return -1;
    }
    if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    Node *current = head;
    while (current != tail)
    {
        current = current->getNext();
    }
    delete tail;
    tail = current;
    tail->setNext(nullptr);

    return 0;
}

int LinkedList::clean()
{
    // Walk through the list, deleting as we go
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->getNext();
        delete current;
        current = next;
    }

    // Reset list to empty
    head = nullptr;
    tail = nullptr;
    return 0;
}
