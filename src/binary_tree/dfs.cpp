#include "binary_tree/binary_tree_node.hpp"
#include "binary_tree/dfs.hpp"
#include <stack>
#include <iostream>
#include <std_aliases.hpp>

using namespace stl;


vector<int> preOrder(TreeNode *tree) {
    std::vector<int> res;
    if (!tree) {
        std::cout << "Tree is empty";
        return res;
    }
    std::stack<TreeNode *> st;
    st.push(tree);
    while (!st.empty()) {
        TreeNode *tempTree = st.top();
        st.pop();
        std::cout << tempTree->m_value << " ";
        //Counterintuitive!
        if (tempTree->right) st.push(tempTree->right); // if we want preorder we need to first push the right subtree!

        if (tempTree->left) st.push(tempTree->left);
    }
    return res;
}

vector<int> inOrder(TreeNode *tree) {
    std::vector<int> res;
    if (!tree) {
        std::cout << "Tree is empty";
        return res;
    }
    std::stack<TreeNode *> st;
    TreeNode* currentNode=tree;
    while (currentNode||!st.empty()) {
        while (currentNode) {
            st.push(currentNode);
            currentNode=currentNode->left;
        }
        currentNode=st.top();
        st.pop();
        res.push_back(currentNode->m_value);

        currentNode=currentNode->right;
    }
    return res;
}

//reverse preorder [NOT CLASSIC]
void reversePreOrder(TreeNode *tree) {
    if (!tree) {
        std::cout << "Tree is empty";
        return;
    }
    std::stack<TreeNode *> q;
    q.push(tree);
    while (!q.empty()) {
        TreeNode *tempTree = q.top();
        q.pop();
        std::cout << tempTree->m_value << " ";
        if (tempTree->left) q.push(tempTree->left);
        if (tempTree->right) q.push(tempTree->right);

        std::cout << "\n";
    }
}


void preOrderRecursive(TreeNode* node,std::vector<TreeNode*>& order){
    if (node== nullptr){
        return;
    }
    order.push_back(node);
    preOrderRecursive(node->left,order);
    preOrderRecursive(node->right,order);
}

void inOrderRecursive(TreeNode* node,std::vector<TreeNode*>& order){
    if (node== nullptr){
        return;
    }
    inOrderRecursive(node->left,order);
    order.push_back(node); //you may also use node->m_value to get value immediately.
    inOrderRecursive(node->right,order);
}


void postOrderRecursive(TreeNode* node,std::vector<TreeNode*>& order){
    if (node== nullptr){
        return;
    }

    postOrderRecursive(node->left,order);
    postOrderRecursive(node->right,order);
    order.push_back(node);
}