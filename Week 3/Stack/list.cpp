#include <iostream>
#include "list.h"

using namespace std;

int List::get(int index) /// do phuc tap O(1)
{
    if (index < 0 || index >= size)
    {
        return -1;
    }
    return data[index];
}
void List::insertFirst(int value) /// do phuc tap O(n)
{
    if (size == MAX)
        cout << "full";
    else
    {
        for (int i = size; i > 0; i--)
        {
            data[i] = data[i - 1];
        }
        data[0] = value;
        size++;
    }
}
void List::insertLast(int value) /// do phuc tap O(1)
{
    if (size == MAX)
        cout << "full";
    else
    {
        data[size++] = value;
    }
}
void List::insertAt(int index, int value) /// do phuc tap O(n)
{
    if (index < 0 || index > size)
    {
        return;
    }
    if (size == MAX)
        cout << "full";
    else
    {
        for (int i = size; i >= index; i--)
        {
            data[i + 1] = data[i];
        }
        data[index] = value;
        size++;
    }
}

void List::removeFirst() /// do phuc tap O(n)
{
    if (size == 0)
    {
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
}
void List::removeLast() /// do phuc tap O(1)
{
    if (size == 0)
    {
        return;
    }
    size--;
}
void List::removeAt(int index) /// do phuc tap O(n)
{
    if (size == 0)
    {
        return;
    }
    if (index < 0 || index >= size)
    {
        cout << "Out of range";
    }
    for (int i = index; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
}

void List::print() /// do phuc tap O(n)
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}
void List::printReverse() /// do phuc tap O(n)
{
    for (int i = size - 1; i >= 0; i--)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}
