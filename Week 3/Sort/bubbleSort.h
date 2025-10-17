#ifndef BUBBLESORT_H
#define BUBBLESORT_H

using namespace std;

void bubbleSort(int a[], int n) ///time: O(n^2)
{
    for(int i = n - 1; i > 0; i--){
        bool sorted = true;
        for(int k = 0; k < i; k++){
            if(a[k] > a[k + 1]){
                swap(a[k], a[k + 1]);
                sorted = false;
            }
        }
        if(sorted) break;
    }
}

#endif // BUBBLESORT_H
