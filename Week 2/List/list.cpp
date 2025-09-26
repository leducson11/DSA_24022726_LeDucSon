#include <iostream>
#include "list.h"

using namespace std;

void initList(List &l) { ///do phuc tap O(1)
    l.size = 0;
}

int get(List &l, int index) ///do phuc tap O(1)
{
    if(index < 0 || index >= l.size){
        return -1;
    }
    return l.data[index];
}
void insertFirst(List &l, int value) ///do phuc tap O(n)
{
    if(l.size == MAX) cout << "full";
    else {
        for(int i = l.size; i > 0; i--){
            l.data[i] = l.data[i - 1];
        }
            l.data[0] = value;
            l.size++;
    }
}
void insertLast(List &l, int value) ///do phuc tap O(1)
{
    if(l.size == MAX) cout << "full";
    else{
        l.data[l.size++] = value;
    }
}
void insertAt(List &l, int index, int value) ///do phuc tap O(n)
{
    if(index < 0 || index >= l.size){
        cout << "Out of range";
    }
    if(l.size == MAX) cout << "full";
    else{
        for(int i = l.size; i >= index; i--){
            l.data[i + 1] = l.data[i];
        }
            l.data[index] = value;
            l.size++;
    }
}

void removeFirst(List &l) ///do phuc tap O(n)
{
    if(l.size == 0) cout << "empty";
    for(int i = 0; i < l.size - 1; i++){
        l.data[i] = l.data[i + 1];
    }
    l.size--;

}
void removeLast(List &l) ///do phuc tap O(1)
{
    if(l.size == 0) cout << "empty";
    l.size--;
}
void removeAt(List &l, int index) ///do phuc tap O(n)
{
    if(l.size == 0) cout << "empty";
    if(index < 0 || index >= l.size){
        cout << "Out of range";
    }
    for(int i = index; i < l.size - 1; i++){
        l.data[i] = l.data[i + 1];
    }
    l.size--;
}

void print(List &l) ///do phuc tap O(n)
{
    for(int i = 0; i < l.size; i++){
        cout << l.data[i] << " ";
    }
    cout << endl;
}
void printReverse(List &l) ///do phuc tap O(n)
{
    for(int i = l.size - 1; i >= 0; i--){
        cout << l.data[i] << " ";
    }
    cout << endl;
}
