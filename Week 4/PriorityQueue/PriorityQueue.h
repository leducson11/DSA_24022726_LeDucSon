#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "maxBinaryHeap.h"

class PriorityQueue
{
private:
    MaxBinaryHeap heap;
public:
    void pqinsert(int value)
    {
        heap.insert(value);
    }
    int delMax()
    {
        return heap.delMax();
    }
    bool isEmpty()
    {
        return heap.isEmpty();
    }
    int getMax()
    {
        return heap.maxIndex();
    }
    int getSize()
    {
        return heap.getSize();
    }

};

#endif // PRIORITYQUEUE_H
