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
    void leftRotate(Node<T> *node);
    void rightRotate(Node<T> *node);
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

template<class T>
void RedBlackTree<T>::leftRotate(Node<T> *node) {
    if(node == nullptr || node == this->nil) {
        return;
    }
    Node<T> *exRightChild = node->right;
    if(exRightChild == nullptr || exRightChild == this->nil) {
        return;
    }
    node->right = exRightChild->left;
    if(node->right != nullptr && node->right != this->nil) {
        node->right->parent = node;
    }
    exRightChild->parent = node->parent;
    if(exRightChild->parent == nullptr || exRightChild->parent == this->nil) {
        this->root = exRightChild;
    } else if(node == node->parent->left) {
        node->parent->left = exRightChild;
    } else {
        node->parent->right = exRightChild;
    }
    exRightChild->left = node;
    node->parent = exRightChild;
}

template<class T>
void RedBlackTree<T>::rightRotate(Node<T> *node) {
    if(node == nullptr || node == this->nil) {
        return;
    }
    Node<T> *exLeftChild = node->left;
    if(exLeftChild == nullptr || exLeftChild == this->nil) {
        return;
    }
    node->left = exLeftChild->left;
    if(node->left != nullptr && node->left != this->nil) {
        node->left->parent = node;
    }
    exLeftChild->parent = node->parent;
    if(exLeftChild->parent == nullptr || exLeftChild->parent == this->nil) {
        this->root = exLeftChild;
    } else if(node == node->parent->right) {
        node->parent->right = exLeftChild;
    } else {
        node->parent->left = exLeftChild;
    }
    exLeftChild->right = node;
    node->parent = exLeftChild;
}

#endif //ADS_REDBLACKTREE_H
