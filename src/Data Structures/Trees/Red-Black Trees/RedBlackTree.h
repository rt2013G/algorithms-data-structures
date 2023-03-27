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
    void recolor();
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

template<class T>
void Node<T>::recolor() {
    if(this->color == red) {
        this->color = black;
    } else {
        this->color = red;
    }
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
    void treeInsert(T data);
    void insertFixup(Node<T> *node);
    Node<T> *nil;
private:

};

template<class T>
RedBlackTree<T>::RedBlackTree() {
    this->nil = new Node<T>(0, black);
    this->root = this->nil;
}

template<class T>
void RedBlackTree<T>::printAsciiTree(Node<T> *node, const std::string &prefix, bool isLeft) {
    if(node == nullptr || node == this->nil) {
        return;
    }
    cout << prefix;
    cout << (isLeft ? "|--" : "L--");
    cout << node->data << (node->color ? " black " : " red ") << std::endl;
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

template<class T>
void RedBlackTree<T>::treeInsert(T data) {
    auto *nodeToInsert = new Node<T>(data, red);
    Node<T> *curr = this->nil;
    Node<T> *tmp = this->root;
    while(tmp != this->nil) {
        curr = tmp;
        if(nodeToInsert->data < tmp->data) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }
    nodeToInsert->parent = curr;
    if(curr == this->nil) {
        this->root = nodeToInsert;
    } else if(nodeToInsert->data < curr->data) {
        curr->left = nodeToInsert;
    } else {
        curr->right = nodeToInsert;
    }
    nodeToInsert->left = this->nil;
    nodeToInsert->right = this->nil;
    insertFixup(nodeToInsert);
 }

template<class T>
void RedBlackTree<T>::insertFixup(Node<T> *node) {
    Node<T> *curr = node;
    while(curr->parent->color == red) {
        if(curr->parent == curr->parent->parent->left) {
            Node<T> *uncle = curr->parent->parent->right;
            if(uncle->color == red) {
                uncle->recolor();
                curr->parent->recolor();
                curr->parent->parent->recolor();
                curr = curr->parent->parent;
            } else {
                if(curr == curr->parent->right) {
                    curr = curr->parent;
                    leftRotate(curr);
                }
                curr->parent->recolor();
                curr->parent->parent->recolor();
                rightRotate(curr->parent->parent);
            }
        } else {
            Node<T> *uncle = curr->parent->parent->left;
            if(uncle->color == red) {
                uncle->recolor();
                curr->parent->recolor();
                curr->parent->parent->recolor();
                curr = curr->parent->parent;
            } else {
                if(curr == curr->parent->left) {
                    curr = curr->parent;
                    rightRotate(curr);
                }
                curr->parent->recolor();
                curr->parent->parent->recolor();
                leftRotate(curr->parent->parent);
            }
        }
    }
    this->root->color = black;
}

#endif //ADS_REDBLACKTREE_H
