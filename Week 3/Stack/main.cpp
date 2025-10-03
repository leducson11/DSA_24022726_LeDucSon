#include <iostream>
#include "list.h"
#include "stack.h"
using namespace std;

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Size: " << s.size() << endl; // 3
    cout << "Top: " << s.top() << endl;   // 30

    cout << "Pop: " << s.pop() << endl;           // 30
    cout << "Top after pop: " << s.top() << endl; // 20

    cout << system("pause");
    return 0;
}
