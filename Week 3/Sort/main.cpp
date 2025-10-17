#include <iostream>
#include "selectionSort.h"
#include "insertionSort.h"
#include "bubbleSort.h"
#include "binarySearch.h"

using namespace std;

int main()
{
    int a[] = {64, 25, 12, 22, 11};
    int n = 5;

    cout << "Mang ban dau: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    selectionSort(a, n);
    //insertionSort(a, n);
    //bubbleSort(a, n);
    cout << "Sau sort: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    if (binarySearch(a, n, 12))
        cout << "Found!\n";
    else
        cout << "Not found!\n";

    cout << system("pause");
    return 0;
}
