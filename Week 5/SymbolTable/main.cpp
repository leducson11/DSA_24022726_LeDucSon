#include "symbolTable.h"
#include <iostream>
using namespace std;

int main() {
    symbolTableLList<int, string> st;

    st.put(5, "Five");
    st.put(1, "One");
    st.put(3, "Three");
    st.put(8, "Eight");
    st.put(6, "Six");

    cout << "All keys: ";
    st.keys(); // In ra tất cả key theo thứ tự tăng dần

    cout << "Min key: " << st._min() << endl;
    cout << "Max key: " << st._max() << endl;

    cout << "Value of key 3: " << *st.get(3) << endl;
    cout << "Rank of key 6: " << st._rank(6) << endl;

    cout << "Select(2): " << st.select(2) << endl;
    cout << "Floor(7): " << st.floor(7) << endl;
    cout << "Ceiling(7): " << st.ceiling(7) << endl;

    cout << "Keys in range [2,7]: ";
    st.keys(2, 7);

    cout << "Deleting min and max...\n";
    st.deleteMin();
    st.deleteMax();

    cout << "After delete: ";
    st.keys();

    return 0;
}
