#include "std_aliases.hpp"
#include "binary_tree/binary_tree_node.hpp"
using namespace stl;

void dfs(TreeNode *node,
         vector<int> &currentPath,
         vector<string> &allPaths) {
    // if note is nullptr
    if (!node) return;

    currentPath.push_back(node->m_value);
    if (!node->left && !node->right) {
        //logic what happen when node is a leaf, so we get to the end of the
        string path;
        for (int i = 0; i < currentPath.size(); ++i) {
            if (i > 0) path += "->";
            path += std::to_string(currentPath[i]);
        }
        allPaths.push_back(path);
    } else {
        dfs(node->left, currentPath, allPaths);
        dfs(node->right, currentPath, allPaths);
    }
    currentPath.pop_back();
}


vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> res;
    vector<int> path;
    if (!root) return res;
    dfs(root,path,res);
    return res;
}

