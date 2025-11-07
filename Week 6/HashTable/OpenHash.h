#ifndef OPENHASH_H
#define OPENHASH_H
#include <vector>
#include <iostream>

using namespace std;

class OpenHash
{
private:
    vector<int> table;
    int tableSize;
    const int EMPTY = -1;
    const int DELETED = -2;
public:
    OpenHash(int size) : tableSize(size)
    {
        table.assign(tableSize, EMPTY);
    }
    int hashFunction(int key)
    {
        return key % tableSize;
    }
    void insert(int key)
    {
        int index = hashFunction(key);
        int start = index;
        while(table[index] != EMPTY && table[index] != DELETED){
            index = (index + 1) % tableSize;
            if(index == start){
                //full
                return;
            }
        }
        table[index] = key;
    }
    bool search(int key)
    {
        int index = hashFunction(key);
        int start = index;
        while(table[index] != EMPTY){
            if(table[index] = key){
                return true;
            }
            index = (index + 1) % tableSize;
            if(index == start) break;
        }
        return false;
    }

    void remove(int key)
    {
        int index = hashFunction(key);
        int start = index;
        while(table[index] != EMPTY){
            if(table[index] == key){
            table[index] = DELETED;
            return;
            }
            index = (index + 1) % tableSize;
            if(index == start) break;
        }

    }
    void print()
    {
        for(int i = 0; i < tableSize; i++){
            cout << i << ": " << table[i] << endl;
        }
    }
};

#endif // OPENHASH_H
