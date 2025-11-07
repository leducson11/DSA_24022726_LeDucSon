#ifndef CHAINHASH_H
#define CHAINHASH_H
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class ChainHash
{
private:
    vector<list<int>> table;
    int tableSize;
public:
    ChainHash(int size) : tableSize(size)
    {
        table.resize(tableSize);
    }
    int hashFunction(int key) {
        return key % tableSize;
    }
    void insert(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
    }
    bool search(int key)
    {
        int index = hashFunction(key);
        for(int x : table[index]){
            if(x == key) {
                return true;
            }
        }
        return false;
    }
    void remove(int key)
    {
        int index = hashFunction(key);
        table[index].remove(key);
    }
    void print()
    {
        for(int i = 0; i < tableSize; i++){
            cout << i << ": ";
            for(int x : table[i]){
                cout << x << " -> ";
            }
            cout << "NULL\n";
        }
    }
};

#endif // CHAINHASH_H
