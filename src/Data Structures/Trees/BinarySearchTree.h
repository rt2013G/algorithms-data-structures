/*
 * Implementation of a Binary Search Tree template, every node may store any data T
 */
#ifndef ADS_BINARYSEARCHTREE_H
#define ADS_BINARYSEARCHTREE_H

#include "iostream"
#include "string"
using std::cout;

template <class T>
class Node
{
public:
    explicit Node(T data);
    Node *parent;
    Node *left;
    Node *right;
    T getData();
private:
    T data;
};

template <class T>
Node<T>::Node(T data) {
    this->data = data;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

template <class T>
T Node<T>::getData() {
    return this->data;
}

template <class T>
class BinarySearchTree
{
public:
    BinarySearchTree();
    void printAsciiTree(Node<T> *node, const std::string& prefix, bool isLeft);
    void printInorder(Node<T> *node);
    Node<T> *binarySearch(Node<T> *node, T data);
    Node<T> *minimum(Node<T> *node);
    Node<T> *maximum(Node<T> *node);
    Node<T> *successor(Node<T> *node);
    Node<T> *predecessor(Node<T> *node);
    void treeInsert(T data);
    void treeDelete(T data);
    void transplant(Node<T> *node_u, Node<T> *node_v);
    Node<T> *root;
private:

};

template<class T>
BinarySearchTree<T>::BinarySearchTree() {
    this->root = nullptr;
}

template<class T>
void BinarySearchTree<T>::printAsciiTree(Node<T> *node, const std::string& prefix, bool isLeft) {
    if(node == nullptr) {
        return;
    }
    cout << prefix;
    cout << (isLeft ? "|--" : "L--");
    cout << node->getData() << std::endl;
    printAsciiTree(node->left, prefix + (isLeft ? "|  " : "    "), true);
    printAsciiTree(node->right, prefix + (isLeft ? "|   " : "    "), false);
}

template<class T>
void BinarySearchTree<T>::printInorder(Node<T> *node) {
    if(node == nullptr) return;
    printInorder(node->left);
    cout << node->getData() << std::endl;
    printInorder(node->right);
}

template<class T>
Node<T> *BinarySearchTree<T>::binarySearch(Node<T> *node, T data) {
    Node<T> *curr = node;
    while(curr != nullptr && curr->getData() != data) {
        if(data < curr->getData()) curr = curr->left;
        else curr = curr->right;
    }
    return curr;
}

template<class T>
Node<T> *BinarySearchTree<T>::minimum(Node<T> *node) {
    if(node == nullptr) return node;
    Node<T> *curr = node;
    while(curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}

template<class T>
Node<T> *BinarySearchTree<T>::maximum(Node<T> *node) {
    if(node == nullptr) return node;
    Node<T> *curr = node;
    while(curr->right != nullptr) {
        curr = curr->right;
    }
    return curr;
}

template<class T>
Node<T> *BinarySearchTree<T>::successor(Node<T> *node) {
    if(node == nullptr) return node;
    Node<T> *curr = node;
    if(curr->right != nullptr) {
        return minimum(curr->right);
    }
    Node<T> *parent = curr->parent;
    while(parent != nullptr && curr == parent->right) {
        curr = parent;
        parent = parent->parent;
    }
    return parent;
}

template<class T>
Node<T> *BinarySearchTree<T>::predecessor(Node<T> *node) {
    if(node == nullptr) return node;
    Node<T> *curr = node;
    if(curr->left != nullptr) {
        return maximum(curr->left);
    }
    Node<T> *parent = curr->parent;
    while(parent != nullptr && curr == parent->left) {
        curr = parent;
        parent = parent->parent;
    }
    return parent;
}

template<class T>
void BinarySearchTree<T>::treeInsert(T data) {
    Node<T> *tmp = nullptr;
    Node<T> *curr = this->root;
    while(curr != nullptr) {
        tmp = curr;
        if(data < curr->getData()) curr = curr->left;
        else curr = curr->right;
    }
    auto *newNode = new Node<T>(data);
    if(tmp == nullptr) {
        this->root = newNode;
        return;
    }
    newNode->parent = tmp;
    if(data < tmp->getData()) tmp->left = newNode;
    else tmp->right = newNode;
}

template<class T>
void BinarySearchTree<T>::treeDelete(T data) {
    Node<T> *nodeToDelete = binarySearch(this->root, data);
    if(nodeToDelete == nullptr) return;
    if(nodeToDelete->left == nullptr) transplant(nodeToDelete, nodeToDelete->right);
    else if(nodeToDelete->right == nullptr) transplant(nodeToDelete, nodeToDelete->left);
    else {
        Node<T> *tmp = minimum(nodeToDelete->right);
        if(tmp->parent != nodeToDelete) {
            transplant(tmp, tmp->right);
            tmp->right = nodeToDelete->right;
            tmp->right->parent = tmp;
        }
        transplant(nodeToDelete, tmp);
        tmp->left = nodeToDelete->left;
        tmp->left->parent = tmp;
    }
}

template<class T>
void BinarySearchTree<T>::transplant(Node<T> *node_u, Node<T> *node_v) {
    if(node_u == nullptr) return;
    if(node_u->parent == nullptr) {
        this->root = node_v;
    } else if(node_u == node_u->parent->left) {
        node_u->parent->left = node_v;
    } else {
        node_u->parent->right = node_v;
    }
    if(node_v != nullptr) {
        node_v->parent = node_u->parent;
    }
}

#endif //ADS_BINARYSEARCHTREE_H
