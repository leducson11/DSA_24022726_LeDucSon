#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main() {
    PriorityQueue pq;

    pq.pqinsert(10);
    pq.pqinsert(40);
    pq.pqinsert(20);

    cout << "Max: " << pq.getMax() << endl;     // 40
    cout << "delMax: " << pq.delMax() << endl; // 40
    cout << "Now max: " << pq.getMax() << endl; // 20
    cout << "Size: " << pq.getSize() << endl;   // 2
    cout << "Empty? " << (pq.isEmpty() ? "Yes" : "No") << endl; // No

    return 0;
}
