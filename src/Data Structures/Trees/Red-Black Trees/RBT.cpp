#include "iostream"
#include "RedBlackTree.h"

int main()
{
    RedBlackTree<int> RBT;
    for(int i = 0; i < 20; i++) {
        RBT.treeInsert(i);
    }
    RBT.printAsciiTree(RBT.root, "", false);
    return 0;
}
