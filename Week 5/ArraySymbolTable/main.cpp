#include "SymbolTable_OArray.h"
#include <iostream>

using namespace std;

int main() {
    OrderedArrayST<string, int> st;

    cout << "=== Insert elements ===" << endl;
    st.put("E", 5);
    st.put("A", 1);
    st.put("C", 3);
    st.put("B", 2);
    st.put("D", 4);

    cout << "All keys in order: ";
    st.printKeys(); // A B C D E

    cout << "\nSize: " << st.getSize() << endl;
    cout << "Min: " << st.min() << endl;
    cout << "Max: " << st.max() << endl;

    cout << "\n=== Test get() ===" << endl;
    cout << "Key C has value: " << *st.get("C") << endl;

    cout << "\n=== Test update ===" << endl;
    st.put("C", 33);
    cout << "Key C after update: " << *st.get("C") << endl;

    cout << "\n=== Test remove ===" << endl;
    st.remove("B");
    cout << "After removing B: ";
    st.printKeys();

    cout << "\n=== Test floor() & ceiling() ===" << endl;
    cout << "floor(D) = " << st.floor("D") << endl;
    cout << "ceiling(D) = " << st.ceiling("D") << endl;

    cout << "\n=== Test select() ===" << endl;
    cout << "select(0): " << st.select(0) << endl;
    cout << "select(2): " << st.select(2) << endl;

    cout << "\n=== Test deleteMin() and deleteMax() ===" << endl;
    st.deleteMin();
    st.deleteMax();
    st.printKeys();

    cout << "\n=== Test keys(lo, hi) ===" << endl;
    cout << "keys between A and E: ";
    st.printKeysInRange("A", "E");
    return 0;
}
