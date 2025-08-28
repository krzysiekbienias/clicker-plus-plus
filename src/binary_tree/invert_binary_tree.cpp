#include "binary_tree/binary_tree_node.hpp"
#include "binary_tree/invert_binary_tree.hpp"
#include <queue>
#include <any>


void invertBinaryTree(BinaryTreeNode* tree) {
    if (tree==nullptr) {
        return;
    }
    std::swap(tree->left,tree->right);
    invertBinaryTree(tree->left);
    invertBinaryTree(tree->right);

}


void invertBinaryTreeBFS(BinaryTreeNode* tree) {
    if (!tree) return ;
    std::queue<BinaryTreeNode*> q;
    q.push(tree);
    while (!q.empty()) {
        BinaryTreeNode *tempNode = q.front();
        q.pop();
        std::swap(tempNode->left, tempNode->right);
        if (tempNode->left) q.push(tempNode->left);
        if (tempNode->right) q.push(tempNode->right);
    }
}
