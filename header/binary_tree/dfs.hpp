#pragma once
#include "binary_tree/binary_tree_node.hpp"
#include <vector>

void reversePreOrder(BinaryTreeNode* tree);
void preOrder(BinaryTreeNode* tree);
void inOrder(BinaryTreeNode* tree);
void inOrderRecursive(BinaryTreeNode* tree,std::vector<BinaryTreeNode*>& order);
void preOrderRecursive(BinaryTreeNode* tree,std::vector<BinaryTreeNode*>& order);
void postOrderRecursive(BinaryTreeNode* tree,std::vector<BinaryTreeNode*>& order);


void postOrder(BinaryTreeNode* tree);