#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "maxBinaryHeap.h"

using namespace std;

void heapSort(int a[], int n) /// O(n log n)
{
    MaxBinaryHeap heap;
    for(int i = 0; i < n; i++){
        heap.insert(a[i]);
    }
    for(int i = n - 1; i >= 0; i--){
        a[i] = heap.delMax();
    }
}

#endif // HEAPSORT_H
