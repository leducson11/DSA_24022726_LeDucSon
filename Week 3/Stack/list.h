#ifndef LIST_H
#define LIST_H

const int MAX = 1001;

struct List
{
    int data[MAX];
    int size;

    List()
    {
        size = 0;
    }

    int get(int index);

    void insertFirst(int value);
    void insertLast(int value);
    void insertAt(int index, int value);

    void removeFirst();
    void removeLast();
    void removeAt(int index);

    void print();
    void printReverse();
};

#endif // LIST_H
