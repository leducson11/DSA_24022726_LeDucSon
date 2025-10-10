#ifndef MAXBINARYHEAP_h
#define MAXBINARYHEAP_H

class MaxBinaryHeap{
private:
    //int Max_Size = 100;
    int arr[101];
    int size;

    void swap(int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
public:
    MaxBinaryHeap()
    {
        size = 0;
    }
    bool isEmpty()
    {
        return size <= 0;
    }
    int getSize() {
        return size;
    }
    int maxIndex() ///tra ve phan tu lon nhat
    {
        if(isEmpty()){
            return -1;
        }
        return arr[1];
    }
    void insert(int data)
    {
        size++;
        arr[size] = data;
        //swim
        int curIndex = size;
        int parentIndex = curIndex / 2;
        while(parentIndex != 0 && arr[parentIndex] < arr[curIndex]){
            swap(parentIndex, curIndex);
            curIndex = parentIndex;
            parentIndex = curIndex / 2;
        }
    }
    int delMax()
    {
        if(isEmpty()){
            return -1;
        }
        int Max = arr[1];
        //sink
        arr[1] = arr[size];
        size--;

        int curIndex = 1;
        while((curIndex * 2) <= size){
            int leftChildIndex = 2 * curIndex;
            int rightChildIndex = leftChildIndex + 1;
            int minChildIndex = leftChildIndex;
            if(rightChildIndex <= size && arr[rightChildIndex] > arr[leftChildIndex]){
                minChildIndex = rightChildIndex;
            }

            if(arr[curIndex] < arr[minChildIndex]){
                swap(curIndex, minChildIndex);
                curIndex = minChildIndex;
            } else {
                break;
            }
        }
        return Max;
    }
};

#endif // MAXBINARYHEAP_h

