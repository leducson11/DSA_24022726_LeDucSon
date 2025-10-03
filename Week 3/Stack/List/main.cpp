#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    List l;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        l.insertLast(x);
    }

    // l.insertFirst(10);
    // l.insertLast(20);pp
    // l.insertAt(3, 30);

    // l.removeFirst();
    // l.removeLast();
    // l.removeAt(2);

    l.print();
    l.printReverse();
    // system("pause");
    return 0;
}
