#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Size: " << q.size() << endl;   // 3
    cout << "Front: " << q.front() << endl; // 10

    cout << "Dequeue: " << q.dequeue() << endl;           // 10
    cout << "Front after dequeue: " << q.front() << endl;
    cout << system("pause");
    return 0;
}
