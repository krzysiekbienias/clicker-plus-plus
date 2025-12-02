

// Implement your find_successor logic here.
#include <vector>
#include "binary_tree/find_successor.hpp"
#include "binary_tree/binary_tree_node.hpp"
#include "binary_tree/dfs.hpp"

// Declare your find_successor interface here.
TreeNode *findSuccessor(TreeNode *tree, TreeNode *node) {
    std::vector<TreeNode *> inorderTraversal;
    inOrderRecursive(tree, inorderTraversal);
    for (int i = 0; i < inorderTraversal.size() - 1; ++i) {
        TreeNode *currentNode = inorderTraversal[i];
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


TreeNode * getLeftmost(TreeNode* node) {
    if (node==nullptr) return nullptr;
    while (node->left!=nullptr)
        node=node->left;
    return node;
}
TreeNode* findSuccessorUsingParentPointer(TreeNode* node) {

}