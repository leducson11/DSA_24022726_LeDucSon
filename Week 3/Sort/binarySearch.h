#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

using namespace std;

bool binarySearch(int a[], int n, int x) ///time: O(log n)
{
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x) {
            return true;
        }
        else if (a[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

#endif // BINARYSEARCH_H
