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
    }
}

void preOrderRecursive(BinaryTreeNode* node,std::vector<BinaryTreeNode*>& order){
    if (node== nullptr){
        return;
    }
    order.push_back(node);
    preOrderRecursive(node->left,order);
    preOrderRecursive(node->right,order);
}

void inOrderRecursive(BinaryTreeNode* node,std::vector<BinaryTreeNode*>& order){
    if (node== nullptr){
        return;
    }
    inOrderRecursive(node->left,order);
    order.push_back(node); //you may also use node->m_value to get value immediately.
    inOrderRecursive(node->right,order);
}


void postOrderRecursive(BinaryTreeNode* node,std::vector<BinaryTreeNode*>& order){
    if (node== nullptr){
        return;
    }

    postOrderRecursive(node->left,order);
    postOrderRecursive(node->right,order);
    order.push_back(node);
}