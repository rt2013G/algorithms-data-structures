#ifndef ADS_REDBLACKTREE_H
#define ADS_REDBLACKTREE_H

#include "iostream"
#include "string"
using std::cout;
enum color {red = 0, black = 1};

template <class T>
class Node
{
public:
    Node(T data, int color);
    Node<T> *parent;
    Node<T> *left;
    Node<T> *right;
    int color{};
    T data;
private:
};

template<class T>
Node<T>::Node(T data, int color) {
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->data = data;
    this->color = color;
}

template <class T>
class RedBlackTree
{
public:
    RedBlackTree();
    void printAsciiTree(Node<T> *node, const std::string& prefix, bool isLeft);
    void printInorder(Node<T> *node);
    Node<T> *binarySearch(Node<T> *node, T data);
    Node<T> *minimum(Node<T> *node);
    Node<T> *maximum(Node<T> *node);
    Node<T> *successor(Node<T> *node);
    Node<T> *predecessor(Node<T> *node);
    Node<T> *root;
private:
    Node<T> *nil;

};

template<class T>
RedBlackTree<T>::RedBlackTree() {
    this->root = nullptr;
    this->nil = new Node<int>(0, black);
}

template<class T>
void RedBlackTree<T>::printAsciiTree(Node<T> *node, const std::string &prefix, bool isLeft) {
    if(node == nullptr || node == this->nil) {
        return;
    }
    cout << prefix;
    cout << (isLeft ? "|--" : "L--");
    cout << node->data << std::endl;
    printAsciiTree(node->left, prefix + (isLeft ? "|  " : "    "), true);
    printAsciiTree(node->right, prefix + (isLeft ? "|   " : "    "), false);
}

template<class T>
void RedBlackTree<T>::printInorder(Node<T> *node) {
    if(node == nullptr || node == this->nil) return;
    printInorder(node->left);
    cout << node->data << std::endl;
    printInorder(node->right);
}

template<class T>
Node<T> *RedBlackTree<T>::binarySearch(Node<T> *node, T data) {
    Node<T> *curr = node;
    while(curr != nullptr && curr != this->nil && curr->data != data) {
        if(data < curr->data) curr = curr->left;
        else curr = curr->right;
    }
    return curr;
}

template<class T>
Node<T> *RedBlackTree<T>::minimum(Node<T> *node) {
    if(node == nullptr || node == this->nil) return node;
    Node<T> *curr = node;
    while(curr->left != nullptr && curr != this->nil) {
        curr = curr->left;
    }
    return curr;
}

template<class T>
Node<T> *RedBlackTree<T>::maximum(Node<T> *node) {
    if(node == nullptr || node == this->nil) return node;
    Node<T> *curr = node;
    while(curr->right != nullptr && curr != this->nil) {
        curr = curr->right;
    }
    return curr;
}

template<class T>
Node<T> *RedBlackTree<T>::successor(Node<T> *node) {
    if(node == nullptr || node == this->nil) return node;
    Node<T> *curr = node;
    if(curr->right != nullptr && curr->right != this->nil) {
        return minimum(curr->right);
    }
    Node<T> *parent = curr->parent;
    while(parent != nullptr && parent != this->nil && curr == parent->right) {
        curr = parent;
        parent = parent->parent;
    }
    return parent;
}

template<class T>
Node<T> *RedBlackTree<T>::predecessor(Node<T> *node) {
    if(node == nullptr || node == this->nil) return node;
    Node<T> *curr = node;
    if(curr->left != nullptr && curr->left != this->nil) {
        return maximum(curr->left);
    }
    Node<T> *parent = curr->parent;
    while(parent != nullptr && parent != this->nil && curr == parent->left) {
        curr = parent;
        parent = parent->parent;
    }
    return parent;
}

#endif //ADS_REDBLACKTREE_H
