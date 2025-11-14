#pragma once
#include "binary_tree/binary_tree_node.hpp"
#include <vector>

void reversePreOrder(TreeNode* tree);
std::vector<int> preOrder(TreeNode *tree);
std::vector<int> inOrder(TreeNode *tree);
void inOrderRecursive(TreeNode* tree,std::vector<TreeNode*>& order);
void preOrderRecursive(TreeNode* tree,std::vector<TreeNode*>& order);
void postOrderRecursive(TreeNode* tree,std::vector<TreeNode*>& order);


void postOrder(TreeNode* tree);