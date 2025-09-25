#include <iostream>
#include "list.h"
using namespace std;

int main() {
    List l;
    initList(l);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertLast(l, x);
    }

    //insertFirst(l, 10);
    //insertLast(l, 20);
    //insertAt(l, 3, 30);

    //removeFirst(l);
    //removeLast(l);
    //removeAt(l, 2);

    print(l);
    printReverse(l);
    return 0;
}
