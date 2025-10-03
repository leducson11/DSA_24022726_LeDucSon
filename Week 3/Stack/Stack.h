#ifndef STACK_H
#define STACK_H

#include "list.h"
#include <iostream>
using namespace std;

struct Stack
{
    List l;

    bool isEmpty()
    {
        return l.size == 0;
    }

    void push(int item)
    {
        l.insertLast(item);
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack rong!\n";
            return -1;
        }
        int value = l.data[l.size - 1];
        l.removeLast();
        return value;
    }

    int size()
    {
        return l.size;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack rong!\n";
            return -1;
        }
        return l.data[l.size - 1];
    }
};

#endif // STACK_H
