#include <std_aliases.hpp>
using namespace stl;
#include "binary_tree/binary_tree_node.hpp"

int closestValueHelper(TreeNode* node,int target, int closest) {
    if (node==nullptr) return closest;

    //update closest we found so far.
    int currentVal=node->m_value;
    if (std::abs(currentVal-target)<std::abs(closest-target))
        closest=currentVal;
    else if (currentVal<target) {
        return closestValueHelper(node->right,target,closest);
    }
    else if (currentVal>target) {
        return closestValueHelper(node->left,target,closest);
    }
}

int findClosestValueInBst(TreeNode* tree, int target) {
    return closestValueHelper(tree,target,tree->m_value);
}