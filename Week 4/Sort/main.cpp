#include <iostream>
#include "mergeSort.h"
#include "quickSort.h"
#include "heapSort.h"

using namespace std;

int main()
{
    int a[] = {64, 25, 12, 22, 11};
    int n = 5;

    cout << "Mang ban dau: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    //mergeSort(a, 0, n - 1);
    //quickSort(a, 0, n - 1);
    heapSort(a, n);
    cout << "Sau sort: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
