#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};
class LinkedList{
private:
    Node *head;
    Node *tail;
    int size;

    void printReverseHelper(Node *node) const
    {
        if (node == nullptr)
            return;
        printReverseHelper(node->next);
        cout << node->data << " ";
    }

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0){}

    ~LinkedList() {
        while(head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty(){
        return head == nullptr;
    }

    int getSize(){
        return size;
    }

    int get(int index) /// do phuc tap O(n)
    {
        if (index < 0 || index >= size){
            return -1;
        }
        Node *temp = head;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }
            return temp->data;
    }
    void insertFirst(int value) /// do phuc tap O(1)
    {
        Node *newNode = new Node(value);
        if(isEmpty()){
            head = tail = newNode;
        }
        else{
        newNode->next = head;
        head = newNode;
        }
        size++;
    }
    void insertLast(int value) /// do phuc tap O(1)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void insertAt(int index, int value) /// do phuc tap O(n)
    {
        if(index < 0 || index > size){
            return;
        }
        if(index == 0){
            insertFirst(value);
            return;
        }
        if (index == size)
        {
            insertLast(value);
            return;
        }
        Node *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }

        Node *newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
    void removeFirst() /// do phuc tap O(1)
    {
        if (isEmpty())
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head == nullptr){
            tail = nullptr;
        }
        delete temp;
        size--;
    }
    void removeLast() /// do phuc tap O(n)
    {
        if (isEmpty()){
            return;
        }
        if (head == tail)
        { 
            delete head;
            head = tail = nullptr;
        } else {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        size--;
    }
    void removeAt(int index) /// do phuc tap O(n)
    {
        if (index < 0 || index >= size){
            return;
        }
        if (index == 0)
        {
            removeFirst();
            return;
        }
        if (index == size - 1)
        {
            removeLast();
            return;
        }
        Node *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }

        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        size--;
    }
    void print() /// do phuc tap O(n)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void printReverse() { /// do phuc tap O(n)
        printReverseHelper(head);
        cout << endl;
    }
};
#endif // LINKEDLIST_H
