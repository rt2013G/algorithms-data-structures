#include "BinarySearchTree.h"
#include "algorithm"
#include "random"

int main()
{
    BinarySearchTree<int> BST;
    std::vector<int> vector = {1, 2, 3, 4, 5, 6};
    std::shuffle(vector.begin(), vector.end(), std::mt19937(std::random_device()()));
    for(int i : vector) {
        BST.treeInsert(i);
    }
    BST.printAsciiTree(BST.root, "", false);
    BST.printInorder(BST.root);
    std::cout << std::endl;
    BST.treeDelete(3);
    BST.treeDelete(1);
    BST.printAsciiTree(BST.root, "", false);
    BST.printInorder(BST.root);

    return 0;
}
