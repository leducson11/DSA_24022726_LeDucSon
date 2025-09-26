#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

struct Node
{
    int data;
    Node* next;
};
Node* initNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

int get(Node* head, int index) ///do phuc tap O(n)
{
    Node* temp = head;
    int i = 0;
    while(temp != nullptr && i < index ){
        temp = temp->next;
        i++;
    }
    if(temp == nullptr){
        return -1;
    }
    return temp->data;
}
void insertFirst(Node*& head, int value) ///do phuc tap O(1)
{
    Node* newNode = initNode(value);
    newNode->next = head;
    head = newNode;
}
void insertLast(Node*& head, int value) ///do phuc tap O(n)
{
    Node* newNode = initNode(value);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAt(Node*& head, int index, int value) ///do phuc tap O(n)
{
    if(index == 0){
        insertFirst(head, value);
        return;
    }
    Node* temp = head;
    for(int i = 0; i < index - 1; i++){
        temp = temp->next;
    }
    if(temp == nullptr){
        return;
    }

    Node* newNode = initNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}
void removeFirst(Node*& head) ///do phuc tap O(1)
{
    if(head == nullptr){
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}
void removeLast(Node*& head) ///do phuc tap O(n)
{
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}
void removeAt(Node*& head, int index) ///do phuc tap O(n)
{
    if(index == 0){
        removeFirst(head);
        return;
    }
    Node* temp = head;
    for(int i = 0; i < index - 1; i++){
        temp = temp->next;
    }
    if(temp == nullptr){
        return;
    }

    Node* p = temp->next;
    temp->next = temp->next->next;
    delete p;
}
void print(Node* head) ///do phuc tap O(n)
{
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void printReverse(Node* head) ///do phuc tap O(n)
{
    if(head == nullptr){
        return;
    }
    printReverse(head->next);
    cout << head->data << " ";
}
#endif // LINKEDLIST_H
