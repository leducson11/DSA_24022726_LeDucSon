#include <iostream>
#include "OpenHash.h"
#include "ChainHash.h"

using namespace std;

int main()
{
    OpenHash H1(7);
    H1.insert(10);
    H1.insert(3);
    H1.insert(17); //Var
    H1.print();

    ChainHash h(7);

    h.insert(10);
    h.insert(3);
    h.insert(17);
    h.insert(24);
    h.insert(31);

    h.print();

    cout << "Search 17: " << (h.search(17) ? "Found" : "Not Found") << endl;

    h.remove(17);
    h.print();

    return 0;
}
