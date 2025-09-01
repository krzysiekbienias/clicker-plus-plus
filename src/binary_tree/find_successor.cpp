

// Implement your find_successor logic here.
#include <vector>
#include "binary_tree/find_successor.hpp"
#include "binary_tree/binary_tree_node.hpp"
#include "binary_tree/dfs.hpp"

// Declare your find_successor interface here.
BinaryTreeNode *findSuccessor(BinaryTreeNode *tree, BinaryTreeNode *node) {
    std::vector<BinaryTreeNode *> inorderTraversal;
    inOrderRecursive(tree, inorderTraversal);
    for (int i = 0; i < inorderTraversal.size() - 1; ++i) {
        BinaryTreeNode *currentNode = inorderTraversal[i];
        if (node != currentNode) //we may also compare pointer not value necessary
            continue;
        //when we travers entire inorderTraversal and still not get the node we are looking for
        if (i == inorderTraversal.size() - 1) {
            return nullptr;
        }
        return inorderTraversal[i + 1];

    }
    return nullptr;

}