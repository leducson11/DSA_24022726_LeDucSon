#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <algorithm>

using namespace std;

template<class Key>
struct Node
{
    Key data;
    Node* left;
    Node* right;

    Node(Key value)
    {
        data = value;
        left = right = nullptr;
    }
};

template<class Key>
class BST
{
private:
    Node<Key>* root;

    Node<Key>* put(Node<Key>* node, Key value)
    {
        if(node == nullptr) {
            return new Node<Key>(value);
        }
        if(value < node->data) {
            node->left = put(node->left, value);
        }
        else if(value > node->data){
            node->right = put(node->right, value);
        }
        return node;
    }

    Node<Key>* get(Node<Key>* node, Key value)
    {
        if(node == nullptr || node->data == value){
            return node;
        }
        if(value < node->data){
            return get(node->left, value);
        }
        return get(node->right, value);
    }

    Node<Key>* findMin(Node<Key>* node)
    {
        while(node->left != nullptr){
            node = node->left;
        }
        return node;
    }

    Node<Key>* deleteKey(Node<Key>* node, Key value)
    {
        if(node == nullptr){
            return nullptr;
        }
        if(value < node->data){
            node->left = deleteKey(node->left, value);
        } else if(value > node->data) {
            node->right = deleteKey(node->right, value);
        } else {
            if(node->left == nullptr && node->right == nullptr){
                return nullptr;
            }
            else if(node->left == nullptr){
                return node->right;
            }
            else if(node->right == nullptr){
                return node->left;
            }
            Node<Key>* minRight = findMin(node->right);
            node->data = minRight->data;
            node->right = deleteKey(node->right, minRight->data);
        }
        return node;
    }

    bool isBST(Node<Key>* node, Key* minVal, Key* maxVal)
    {
        if(node == nullptr){
            return true;
        }
        if((minVal && node->data <= *minVal) || (maxVal && node->data >= *maxVal)){
            return false;
        }
        return isBST(node->left, minVal, &node->data) &&
                isBST(node->right, &node->data, maxVal);
    }

    int height(Node<Key>* node)
    {
        if(node == nullptr){
            return 0;
        }
        return 1 + max(height(node->left), height(node->right));
    }
    bool isBalanced(Node<Key>* node)
    {
        if(node == nullptr){
            return true;
        }
        int leftH = height(node->left);
        int rightH = height(node->right);
        if(abs(leftH - rightH) > 1){
            return false;
        }
        return isBalanced(node->left) && isBalanced(node->right);
    }
public:
    BST() {root = nullptr;}
    bool isBinaryTree()
    {
        return true;
    }
    void put(Key value)
    {
        root = put(root, value);
    }
    bool get(Key value)
    {
        return get(root, value) != nullptr;
    }
    void deleteKey(Key value)
    {
        root = deleteKey(root, value);
    }
    bool isBST()
    {
        return isBST(root, nullptr, nullptr);
    }
    bool isBalancedBST()
    {
        return isBST() && isBalanced(root);
    }

};

#endif // BINARYSEARCHTREE_H
