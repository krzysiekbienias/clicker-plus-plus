#include <exception>
#include <stdexcept>

#include "binary_tree/binary_tree_node.hpp"


int evaluateExpressionTree(TreeNode* tree) {
    int currentVal=tree->m_value;
    if (currentVal>0) {
        return currentVal;
    }
    int leftVal=evaluateExpressionTree(tree->left);
    int rightVal=evaluateExpressionTree(tree->right);

    if (tree->m_value==-1) {
        return leftVal+rightVal;
    }
    else if (tree->m_value==-2) {
        return leftVal-rightVal;
    }
    else if (tree->m_value==-3) {
        return leftVal/rightVal;
    }
     else if (tree->m_value==-4){
         return leftVal*rightVal;
    }
    else {
        throw std::logic_error("wrong operations");
    }
}