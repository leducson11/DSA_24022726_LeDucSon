#ifndef QUICKSORT_H
#define QUICKSORT_H

using namespace std;

void quickSort(int a[], int left, int right) ///xau nhat: O(n^2), tbinh: O(n log n)
{
    int i = left, j = right;
    int pivot = a[(left + right) / 2];

    while (i <= j){
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(left < j){
        quickSort(a, left, j);
    }
    if(right > i){
        quickSort(a, i, right);
    }
}

#endif // QUICKSORT_H
