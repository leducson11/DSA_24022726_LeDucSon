#ifndef LIST_H
#define LIST_H

const int MAX = 1001;

struct List{
    int data[MAX];
    int size;
};

int get(List &l,int index);
void initList(List &l);

void insertFirst(List &l, int value);
void insertLast(List &l, int value);
void insertAt(List &l, int index, int value);

void removeFirst(List &l);
void removeLast(List &l);
void removeAt(List &l, int index);

void print(List &l);
void printReverse(List &l);

#endif // LIST_H
