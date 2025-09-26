#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    Node* head = nullptr;

    insertLast(head, 10);
    insertLast(head, 20);
    insertLast(head, 30);
    insertAt(head, 2, 40);

    //removeFirst(head);
    //removeLast(head);
    //removeAt(head, 2);

    print(head);
    printReverse(head);
    cout << endl;
    cout << get(head, 2);


    //print(l);
    //printReverse(l);
    return 0;
}
