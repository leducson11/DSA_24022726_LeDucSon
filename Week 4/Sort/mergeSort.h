#ifndef MERGESORT_H
#define MERGESORT_H

using namespace std;

void Merge(int a[], int left, int mid, int right);

void mergeSort(int a[], int left, int right) /// ttrungbinh O(n log n), xaunhat: O(n^2)
{
    if(left >= right){
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    Merge(a, left, mid, right);
}

void Merge(int a[], int left, int mid, int right)
{
    int sizeL = mid - left + 1;
    int sizeR = right - mid;

    int L[sizeL], R[sizeR];
    for(int i = 0; i < sizeL; i++){
        L[i] = a[left + i];
    }
    for(int j = 0; j < sizeR; j++){
        R[j] = a[mid + 1 + j];
    }

    int i = 0, j = 0, index = left;
    while (i < sizeL && j < sizeR){
        if(L[i] <= R[j]){
            a[index++] = L[i++];
        }
        else {
            a[index++] = R[j++];
        }
    }
    while(i < sizeL){
        a[index++] = L[i++];
    }
    while(j < sizeR){
        a[index++] = R[j++];
    }

}

#endif // MERGESORT_H
