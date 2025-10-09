#include <iostream>
#include "MaxBinaryHeap.h"
using namespace std;

int main() {
    MaxBinaryHeap heap;

    heap.insert(10);
    heap.insert(30);
    heap.insert(5);
    heap.insert(40);
    heap.insert(25);

    cout << "Phan tu lon nhat hien tai: " << heap.maxIndex() << endl;
    cout << "Kich thuoc heap: " << heap.getSize() << endl;

    cout << "Xoa cac phan tu theo thu tu giam dan:\n";
    while (!heap.isEmpty()) {
        cout << heap.delMax() << " ";
    }
    cout << endl;

    return 0;
}
