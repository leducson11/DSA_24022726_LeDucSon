#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

using namespace std;

void insertionSort(int a[], int n) ///time: O(n^2)
{
    for(int i = 1; i < n; i++){
        for(int k = i; k > 0; k--){
            if(a[k] < a[k - 1]){
                swap(a[k], a[k-1]);
            }
            else
            {
                break;
            }
        }
    }
}

#endif // INSERTIONSORT_H
