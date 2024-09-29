#include <iostream>
#include "functions.h"

using namespace std;

void menu()
{
    cout << "1. Stack" << endl;
    cout << "2. Queue" << endl;

    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        Stack stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.printStack();
        cout << "Popped: " << stack.pop() << endl;
        cout << "Popped: " << stack.pop() << endl;
        cout << "Popped: " << stack.pop() << endl;
        cout << "Popped: " << stack.pop() << endl;
        cout << "Popped: " << stack.pop() << endl;
        cout << "Popped: " << stack.pop() << endl;
        break;
    }
    case 2:
    {
        Queue queue;
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        queue.enqueue(5);
        queue.printQueue();
        cout << "Dequeued: " << queue.dequeue() << endl;
        cout << "Dequeued: " << queue.dequeue() << endl;
        cout << "Dequeued: " << queue.dequeue() << endl;
        cout << "Dequeued: " << queue.dequeue() << endl;
        cout << "Dequeued: " << queue.dequeue() << endl;
        cout << "Dequeued: " << queue.dequeue() << endl;
        break;
    }
    default:
        cout << "Invalid choice" << endl;
    }
}

int main()
{
    menu();

    return 0;
}