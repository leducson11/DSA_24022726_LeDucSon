#ifndef BINARYTREE_H
#define BINARYTREE_H

using namespace std;

template<class Item>
struct Node
{
    Item data;
    Node* left;
    Node* right;
};

template<class Item>
void Preorder(Node<Item>* root, void f(Item&))
{
    if(root != nullptr){
        f(root->data);
        Preorder(root->left, f);
        Preorder(root->right, f);
    }
}

template<class Item>
void Inorder(Node<Item>* root, void f(Item&))
{
    if(root != nullptr){
        Inorder(root->left,f);
        f(root->data);
        Inorder(root->right,f);
    }
}

template<class Item>
void Postorder(Node<Item>* root, void f(Item&))
{
    if(root != nullptr){
        Postorder(root->left,f);
        Postorder(root->right,f);
        f(root->data);
    }
}

#endif // BINARYTREE_H
