#include "binary_tree/binary_tree_node.hpp"
#include "binary_tree/invert_binary_tree.hpp"
#include <queue>
#include <any>


void invertBinaryTree(TreeNode* tree) {
    if (tree==nullptr) {
        return;
    }
    std::swap(tree->left,tree->right);
    invertBinaryTree(tree->left);
    invertBinaryTree(tree->right);
}


void invertBinaryTreeBFS(TreeNode* tree) {
    if (!tree) return ;
    std::queue<TreeNode*> q;
    q.push(tree);
    while (!q.empty()) {
        TreeNode *tempNode = q.front();
        q.pop();
        std::swap(tempNode->left, tempNode->right);
        if (tempNode->left) q.push(tempNode->left);
        if (tempNode->right) q.push(tempNode->right);
    }
}
