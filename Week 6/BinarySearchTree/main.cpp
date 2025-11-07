#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(){
    BST<int> tree;

    tree.put(50);
    tree.put(30);
    tree.put(70);
    tree.put(20);
    tree.put(40);
    tree.put(60);
    tree.put(80);

    cout << "Find 40? " << (tree.get(40) ? "YES" : "NO") << endl;
    cout << "Is BST? " << (tree.isBST() ? "YES" : "NO") << endl;
    cout << "Is Balanced BST? " << (tree.isBalancedBST() ? "YES" : "NO") << endl;

    tree.deleteKey(30);

    cout << "After delete 30, find 30? " << (tree.get(30) ? "YES" : "NO") << endl;

    return 0;
}
