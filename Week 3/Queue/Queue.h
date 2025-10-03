#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"
#include <iostream>
using namespace std;

class Queue
{
private:
    LinkedList l;

public:
    Queue() {}

    bool isEmpty()
    {
        return l.isEmpty();
    }

    int size()
    {
        return l.getSize();
    }

    void enqueue(int value)
    {
        l.insertLast(value);
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue rong!\n";
            return -1;
        }
        int value = l.get(0);
        l.removeFirst();
        return value;
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue rong!\n";
            return -1;
        }
        return l.get(0);
    }

};

#endif // QUEUE_H
