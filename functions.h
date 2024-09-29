#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node(int data = 0);
    void setNext(Node *next);
    Node *getNext();
    void setData(int dataValue);
    int getData();
};

// constructor
Node::Node(int data)
{
    this->data = data;
    this->next = nullptr;
}

// set next node
void Node::setNext(Node *next)
{
    this->next = next;
}

// get next node
Node *Node::getNext()
{
    return this->next;
}

// set data
void Node::setData(int dataValue)
{
    this->data = dataValue;
}

// get data
int Node::getData()
{
    return this->data;
}

// Stack class
class Stack
{
    Node *top;
    int count;

public:
    Stack();
    bool isEmpty();
    void push(int data);
    int pop();
    int peek();
    int size();
    void clear();
    void printStack();

    ~Stack();
};

// constructor
Stack::Stack()
{
    this->top = nullptr;
    this->count = 0;
}

// check if stack is empty
bool Stack::isEmpty()
{
    return this->top == nullptr;
}

// push data to stack
void Stack::push(int data)
{
    Node *newNode = new Node(data);
    newNode->setNext(this->top);
    this->top = newNode;
    this->count++;
}

// pop data from stack
int Stack::pop()
{
    if (this->isEmpty())
    {
        cout << "Stack is empty" << endl;
        return -1;
    }

    Node *temp = this->top;
    int data = temp->getData();
    this->top = temp->getNext();
    delete temp;
    this->count--;
    return data;
}

// peek data from stack
int Stack::peek()
{
    if (this->isEmpty())
    {
        cout << "Stack is empty" << endl;
        return -1;
    }

    return this->top->getData();
}

// get size of stack
int Stack::size()
{
    return this->count;
}

// clear stack
void Stack::clear()
{
    while (!this->isEmpty())
    {
        this->pop();
    }
}

// print stack
void Stack::printStack()
{
    Node *temp = this->top;
    while (temp != nullptr)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

// destructor
Stack::~Stack()
{
    this->clear();
}

// Queue class
class Queue
{
    Node *top;
    int count;

public:
    Queue();
    bool isEmpty();
    void enqueue(int data);
    int dequeue();
    int size();
    void printQueue();

    ~Queue();
};

// constructor
Queue::Queue()
{
    this->top = nullptr;
    this->count = 0;
}

// check if queue is empty
bool Queue::isEmpty()
{
    return this->top == nullptr;
}

// dequeue data from queue
void Queue::enqueue(int data)
{
    Node *newNode = new Node(data);
    if (this->isEmpty())
    {
        this->top = newNode;
    }
    else
    {
        Node *temp = this->top;
        this->top = newNode;
        newNode->setNext(temp);
    }
    this->count++;
}

// enqueue data to queue
int Queue::dequeue()
{
    if (this->isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }

    Node *temp = this->top;
    Node *prev = nullptr;
    while (temp->getNext() != nullptr)
    {
        prev = temp;
        temp = temp->getNext();
    }

    int data = temp->getData();

    if (prev != nullptr)
    {
        prev->setNext(nullptr);
    }
    else
    {
        this->top = nullptr;
    }

    this->count--;
    return data;
}

// get size of queue
int Queue::size()
{
    return this->count;
}

// print queue
void Queue::printQueue()
{
    Node *temp = this->top;
    while (temp != nullptr)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

// destructor
Queue::~Queue()
{
    for (int i = 0; i < this->count; i++)
    {
        this->dequeue();
    }
}

#endif // FUNCTIONS_H