#include "binary_tree/binary_tree_node.hpp"
#include "binary_tree/bfs.hpp"

#include <iostream>

void bfsPrint(BinaryTreeNode* tree) {
    if (!tree) {
        std::cout << "Tree is empty";
        return;
    }
    std::queue<BinaryTreeNode *> q;
    q.push(tree);
    while (!q.empty()) {
        int levelSize{static_cast<int>(q.size())};
        while (levelSize--) {
            BinaryTreeNode *tempTree = q.front();
            q.pop();
            std::cout << tempTree->m_value << " ";
            if (tempTree->left) q.push(tempTree->left);
            if (tempTree->right) q.push(tempTree->right);
        }
        std::cout << "\n";
    }
}




