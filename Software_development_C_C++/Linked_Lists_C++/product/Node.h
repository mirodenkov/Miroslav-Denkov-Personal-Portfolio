#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int value;  // holds the content value
    Node *next; // holds a pointer to the next node

public:
    Node() = delete;           // deletes default constructor
    Node(int val);             // constructor
    Node(int val, Node *next); // constructor with next defined
    int getValue() const;      // getter method, gets value
    void setValue(int val);    // setter method, sets value
    Node *getNext() const;     // gets a pointer to the next node
    void setNext(Node *next);  // sets the next node
};

#endif