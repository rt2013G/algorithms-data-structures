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
    Node<T> *binarySearch(Node<T> *node, T data);
    Node<T> *minimum(Node<T> *node);
    Node<T> *maximum(Node<T> *node);
    Node<T> *successor(Node<T> *node);
    Node<T> *predecessor(Node<T> *node);
    void printAsciiTree(Node<T> *node, const std::string& prefix, bool isLeft);
    void printInorder(Node<T> *node);
    void leftRotate(Node<T> *node);
    void rightRotate(Node<T> *node);
    void treeInsert(T data);
    void insertFixup(Node<T> *node);
    void treeDelete(T data);
    void transplant(Node<T> *node_u, Node<T> *node_v);
    void deleteFixup(Node<T> *node);
    Node<T> *root;
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
    while(node->left != nullptr && node != this->nil) {
        node = node->left;
    }
    return node;
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
    if(exRightChild->left != nullptr && exRightChild->left != this->nil) {
        exRightChild->left->parent = node;
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
    node->left = exLeftChild->right;
    if(exLeftChild->right != nullptr && exLeftChild->right != this->nil) {
        exLeftChild->right->parent = node;
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
    Node<T> *node_y = this->nil;
    Node<T> *node_x = this->root;
    while(node_x != this->nil) {
        node_y = node_x;
        if(nodeToInsert->data < node_x->data) {
            node_x = node_x->left;
        } else {
            node_x = node_x->right;
        }
    }
    nodeToInsert->parent = node_y;
    if(node_y == this->nil) {
        this->root = nodeToInsert;
    } else if(nodeToInsert->data < node_y->data) {
        node_y->left = nodeToInsert;
    } else {
        node_y->right = nodeToInsert;
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
                uncle->color = black;
                curr->parent->color = black;
                curr->parent->parent->color = red;
                curr = curr->parent->parent;
            } else {
                if(curr == curr->parent->right) {
                    curr = curr->parent;
                    leftRotate(curr);
                }
                curr->parent->color = black;
                curr->parent->parent->color = red;
                rightRotate(curr->parent->parent);
            }
        } else {
            Node<T> *uncle = curr->parent->parent->left;
            if(uncle->color == red) {
                uncle->color = black;
                curr->parent->color = black;
                curr->parent->parent->color = red;
                curr = curr->parent->parent;
            } else {
                if(curr == curr->parent->left) {
                    curr = curr->parent;
                    rightRotate(curr);
                }
                curr->parent->color = black;
                curr->parent->parent->color = red;
                leftRotate(curr->parent->parent);
            }
        }
    }
    this->root->color = black;
}

/* For some reason trying to delete the root would result in the entire tree getting removed.
 * After playing around for hours with no avail, I decided to give up.
 * If some random person in some random point in the future ever reads this
 * and finds a solution I will be ever grateful.
*/
template<class T>
void RedBlackTree<T>::treeDelete(T data) {
    Node<T> *nodeToDelete = binarySearch(this->root, data);
    if(nodeToDelete == nullptr || nodeToDelete == this->nil) return;
    int originalColor = nodeToDelete->color;
    Node<T> *node_y;
    Node<T> *node_x;
    if(nodeToDelete->left == this->nil) {
        node_x = nodeToDelete->right;
        transplant(nodeToDelete, nodeToDelete->right);
    } else if(nodeToDelete->right == this->nil) {
        node_x = nodeToDelete->left;
        transplant(nodeToDelete, nodeToDelete->left);
    } else {
        node_y = minimum(nodeToDelete->right);
        originalColor = node_y->color;
        node_x = node_y->right;
        if(node_y->parent == nodeToDelete) {
            node_x->parent = node_y;
        } else {
            transplant(node_y, node_y->right);
            node_y->right = nodeToDelete->right;
            node_y->right->parent = node_y;
        }
        transplant(nodeToDelete, node_y);
        node_y->left = nodeToDelete->left;
        node_y->left->parent = node_y;
        node_y->color = nodeToDelete->color;
    }
    delete nodeToDelete;
    if(originalColor == black) {
        deleteFixup(node_x);
    }
}

template<class T>
void RedBlackTree<T>::transplant(Node<T> *node_u, Node<T> *node_v) {
    if(node_u == nullptr || node_v == nullptr) return;
    if(node_u->parent == this->nil) {
        this->root = node_v;
    } else if(node_u == node_u->parent->left) {
        node_u->parent->left = node_v;
    } else {
        node_u->parent->right = node_v;
    }
    node_v->parent = node_u->parent;
}

template<class T>
void RedBlackTree<T>::deleteFixup(Node<T> *node) {
    if(node == nullptr) return;
    Node<T> *node_x = node;
    Node<T> *node_w;
    while(node_x != this->root && node_x->color == black) {
        if(node_x == node_x->parent->left) {
            node_w = node_x->parent->right;
            // case 1
            if(node_w->color == red) {
                node_w->color = black;
                node_x->parent->color = red;
                leftRotate(node_x->parent);
                node_w = node_x->parent->right;
            }
            // case 2
            if(node_w->left->color == black && node_w->right->color == black) {
                node_w->color = red;
                node_x = node_x->parent;
            } else {
                // case 3
                if(node_w->right->color == black) {
                    node_w->left->color = black;
                    node_w->color = red;
                    rightRotate(node_w);
                    node_w = node_x->parent->right;
                }
                // case 4
                node_w->color = node_w->parent->color;
                node_w->parent->color = black;
                node_w->right->color = black;
                leftRotate(node_x->parent);
                node_x = this->root;
            }
        } else {  // completely symmetrical to the if part
            node_w = node_x->parent->left;
            if(node_w->color == red) {
                node_w->color = black;
                node_x->parent->color = red;
                rightRotate(node_x->parent);
                node_w = node_x->parent->left;
            }
            if(node_w->left->color == black && node_w->right->color == black) {
                node_w->color = red;
                node_x = node_x->parent;
            } else {
                if(node_w->left->color == black) {
                    node_w->right->color = black;
                    node_w->color = red;
                    leftRotate(node_w);
                    node_w = node_x->parent->left;
                }
                node_w->color = node_w->parent->color;
                node_w->parent->color = black;
                node_w->left->color = black;
                rightRotate(node_x->parent);
                node_x = this->root;
            }
        }
    }
    node_x->color = black;
}

#endif //ADS_REDBLACKTREE_H
