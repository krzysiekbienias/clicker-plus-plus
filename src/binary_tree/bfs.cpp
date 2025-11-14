#include "binary_tree/binary_tree_node.hpp"
#include "binary_tree/bfs.hpp"
#include "std_aliases.hpp"
#include <iostream>

using namespace stl;

vector<vector<int>> bsfTree(TreeNode* tree) {
    vector<vector<int>> result;
    if (tree==nullptr) return result;
    queue<TreeNode*> q;
    q.push(tree);

    while (!q.empty()) {
        int levelSize=q.size();
        vector<int> currentLevel;
        for (int i=0;i<levelSize;++i){
            TreeNode* node=q.front();
            q.pop();
            currentLevel.push_back(node->m_value);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.emplace_back(currentLevel);
    }
    return result;

}

// Helper function to print the result for bfsTree function
void printResult(const std::vector<std::vector<int>>& result) {
    std::cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j];
            if (j < result[i].size() - 1) std::cout << ",";
        }
        std::cout << "]";
        if (i < result.size() - 1) std::cout << ",";
    }
    std::cout << "]" << std::endl;
}


void bfsPrint(TreeNode* tree) {
    if (!tree) {
        std::cout << "Tree is empty";
        return;
    }
    std::queue<TreeNode *> q;
    q.push(tree);
    while (!q.empty()) {
        int levelSize{static_cast<int>(q.size())};
        while (levelSize--) {
            TreeNode *tempTree = q.front();
            q.pop();
            std::cout << tempTree->m_value << " ";
            if (tempTree->left) q.push(tempTree->left);
            if (tempTree->right) q.push(tempTree->right);
        }
        std::cout << "\n";
    }
}




