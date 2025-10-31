#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename Key, typename Value>
class symbolTableLList
{
    struct Node
    {
        Key key;
        Value val;
        Node* next;
        Node(Key k, Value v) : key(k), val(v), next(nullptr) {}
    };
    Node* head = nullptr;
    int size;
public:
    symbolTableLList() : head(nullptr), size(0) {}

    void put(Key k, Value v) ///do phuc tap O(n)
    {
        if(!head || k < head->key)
        {
            Node* newNode = new Node(k, v);
            newNode->next = head;
            head = newNode;
            size++;
            return;
        }
        Node* cur = head;
        while (cur->next && cur->next->key < k)
            cur = cur->next;

        if (cur->next && cur->next->key == k)
            cur->next->val = v;
        else
        {
            Node* newNode = new Node(k, v);
            newNode->next = cur->next;
            cur->next = newNode;
            size++;
        }

    }

    Value* get(Key k) ///do phuc tap O(n)
    {
        for(Node* cur = head; cur; cur = cur->next)
        {
            if(cur->key == k)
            {
                return &cur->val;
            }
        }
        return nullptr;
    }

    Key _min()
    {
        return head->key;
    }
    Key _max()
    {
        Node* cur = head;
        while(cur->next)
            cur = cur->next;
        return cur->key;
    }

    Key floor(Key k) ///do phuc tap O(n)
    {
        if (!head)
            throw runtime_error("Symbol table is empty");
        if (k < head->key)
            throw runtime_error("No floor key exists");

        Node* cur = head;
        Key floorKey = head->key;

        while (cur && cur->key <= k)
        {
            floorKey = cur->key;
            cur = cur->next;
        }

        return floorKey;
    }

    Key ceiling(Key k) ///do phuc tap O(n)
    {
        if (!head)
            throw runtime_error("Symbol table is empty");

        for (Node* cur = head; cur; cur = cur->next)
            if (cur->key >= k)
                return cur->key;

        throw runtime_error("No ceiling key exists");
    }

    int _rank(Key k)
    {
        int dem = 0;
        for(Node* cur = head; cur; cur = cur->next)
        {
            if(cur->key < k)
                dem++;
        }
        return dem;
    }
    /// dua ra khoa o vi tri thu k
    Key select(int k)
    {
        int idx = 0;
        for (Node* cur = head; cur; cur = cur->next)
            if (idx++ == k)
                return cur->key;
        throw runtime_error("Index out of range");
    }
    void deleteMin()
    {
        if(!head)
        {
            return;
        }
        Node* tmp = head;
        head = head->next;
        delete tmp;
        size--;
    }
    void deleteMax()
    {
        if (!head)
            return;
        if (!head->next)
        {
            delete head;
            head = nullptr;
            size--;
            return;
        }
        Node* cur = head;
        while(cur->next->next)
            cur = cur->next;
        delete cur->next;
        cur->next = nullptr;
        size--;
    }
    int _size(Key lo, Key hi)
    {
        int dem = 0;
        for(Node* cur = head; cur; cur = cur->next)
        {
            if(cur->key >= lo && cur->key <= hi)
            {
                dem++;
            }
        }
        return dem;
    }
    void keys(Key lo, Key hi)
    {
        for (Node* cur = head; cur; cur = cur->next)
            if (cur->key >= lo && cur->key <= hi)
                cout << cur->key << " ";
        cout << endl;
    }

    void keys()
    {
        keys(_min(), _max());
    }

    ~symbolTableLList()
    {
        while (head)
        {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};

#endif // SYMBOLTABLE_H
