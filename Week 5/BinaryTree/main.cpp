#include <iostream>
#include "BinaryTree.h"

using namespace std;

void printInt(int &x)
{
    cout << x << " ";
}

int main()
{
    Node<int>* root = new Node<int>{1, nullptr, nullptr};
    root->left = new Node<int>{2, nullptr, nullptr};
    root->right = new Node<int>{3, nullptr, nullptr};
    root->left->left = new Node<int>{4, nullptr, nullptr};
    root->left->right = new Node<int>{5, nullptr, nullptr};

    Preorder(root, printInt);
    cout << endl;
    Inorder(root, printInt);
    cout << endl;
    Postorder(root, printInt);
    return 0;
}
