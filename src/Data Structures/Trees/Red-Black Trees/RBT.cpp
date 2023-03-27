#include "RedBlackTree.h"

int main()
{
    RedBlackTree<int> RBT;
    RBT.treeInsert(7);
    RBT.treeInsert(3);
    RBT.treeInsert(2);
    RBT.treeInsert(5);
    RBT.treeInsert(8);
    RBT.treeInsert(6);
    RBT.treeDelete(6);
    RBT.printAsciiTree(RBT.root, "", false);
    return 0;
}
