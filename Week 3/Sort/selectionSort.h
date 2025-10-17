#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

using namespace std;

void selectionSort(int a[], int n) ///time: O(n^2)
{
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[minIndex]){
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

#endif // SELECTIONSORT_H
