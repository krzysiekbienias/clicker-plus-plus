#include "binary_tree/binary_tree_node.hpp"
#include "binary_tree/dfs.hpp"
#include <stack>
#include <iostream>

//reverse preorder [NOT CLASSIC]
void reversePreOrder(BinaryTreeNode *tree) {
    if (!tree) {
        std::cout << "Tree is empty";
        return;
    }
    std::stack<BinaryTreeNode *> q;
    q.push(tree);
    while (!q.empty()) {
        BinaryTreeNode *tempTree = q.top();
        q.pop();
        std::cout << tempTree->m_value << " ";
        if (tempTree->left) q.push(tempTree->left);
        if (tempTree->right) q.push(tempTree->right);

        std::cout << "\n";
    }
}


void preOrder(BinaryTreeNode *tree) {
    if (!tree) {
        std::cout << "Tree is empty";
        return;
    }
    std::stack<BinaryTreeNode *> q;
    q.push(tree);
    while (!q.empty()) {
        BinaryTreeNode *tempTree = q.top();
        q.pop();
        std::cout << tempTree->m_value << " ";
        //Counterintuitive!
        if (tempTree->right) q.push(tempTree->right); // if we want preorder we need to first push the right subtree!

        if (tempTree->left) q.push(tempTree->left);

        std::cout << "\n";
    }
}
