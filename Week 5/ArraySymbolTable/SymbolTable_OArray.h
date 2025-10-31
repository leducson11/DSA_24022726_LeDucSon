#ifndef SYMBOLTABLE_OARRAY_H
#define SYMBOLTABLE_OARRAY_H
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename Key, typename Value>
class OrderedArrayST
{
private:
    vector<Key> keys;
    vector<Value> vals;

    int getIndex(Key key) const
    {
        int lo = 0, hi = keys.size() - 1;
        while(lo <= hi){
            int mid = (hi + lo) / 2;
            if(key < keys[mid]) hi = mid - 1;
            else if(key > keys[mid]) lo = mid + 1;
            else return mid;
        }
        return lo;
    }
public:
    OrderedArrayST() {}
    int getSize() const{ return keys.size();}
    bool isEmpty() const {return keys.empty();}

    Value* get(Key key)
    {
        if (isEmpty()) return nullptr;
        int i = getIndex(key);
        if (i < getSize() && keys[i] == key) return &vals[i];
        return nullptr;
    }
    void put(Key key, Value val) {
        int i = getIndex(key);
        if (i < getSize() && keys[i] == key) {
            vals[i] = val;
            return;
        }
        keys.insert(keys.begin() + i, key);
        vals.insert(vals.begin() + i, val);
    }
    void remove(Key key)
    {
        if(isEmpty()) return;
        int i = getIndex(key);
        if(i < getSize() && keys[i] == key){
            keys.erase(keys.begin() + i);
            vals.erase(vals.begin() + i);
        }
    }

    Key min() const {
        if (isEmpty()) throw runtime_error("Table empty");
        return keys.front();
    }

    Key max() const {
        if (isEmpty()) throw runtime_error("Table empty");
        return keys.back();
    }
    int _rank(Key key) const {
        return getIndex(key);
    }
    void printKeys() const {
        for (auto& k : keys) cout << k << " ";
        cout << endl;
    }

    void printKeysInRange(Key lo, Key hi) const {
        for (auto& k : keys)
            if (k >= lo && k <= hi)
                cout << k << " ";
        cout << endl;
    }
    Key floor(Key key) const {
        int i = getIndex(key);
        if (i < getSize() && keys[i] == key) return keys[i];
        if (i == 0) throw runtime_error("No floor key");
        return keys[i - 1];
    }

    Key ceiling(Key key) const {
        int i = getIndex(key);
        if (i == getSize()) throw runtime_error("No ceiling key");
        return keys[i];
    }
    Key select(int k) const {
        if (k < 0 || k >= getSize()) throw runtime_error("Index out of range");
        return keys[k];
    }
    void deleteMin() {
        if (isEmpty()) return;
        keys.erase(keys.begin());
        vals.erase(vals.begin());
    }

    void deleteMax() {
        if (isEmpty()) return;
        keys.pop_back();
        vals.pop_back();
    }

    int _size(Key lo, Key hi) const {
        if (hi < lo) return 0;
        int i = getIndex(lo);
        int j = getIndex(hi);
        if (j < getSize() && keys[j] == hi) j++;
        return j - i;
    }
};

#endif // SYMBOLTABLE_OARRAY_H
