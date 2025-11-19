#include "std_aliases.hpp"

#include "binary_tree/binary_tree_node.hpp"

using namespace stl;
//uwaga to nie moze byc void
bool dfsPath(TreeNode* node,int B, vector<int>&path) {
    if (!node) return false;
    path.push_back(node->m_value);
    if (node->m_value==B) return true;
    if (dfsPath(node->left,B,path)||dfsPath(node->right,B,path))
        return true;
    path.pop_back(); //backtrack
    return false;
}

vector<int> pathToNode(TreeNode* A, int B) {
    vector<int> path;
    dfsPath(A,B,path);
    return path;
}

