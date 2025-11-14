#pragma once
#include<vector>
#include "binary_tree/binary_tree_node.hpp"

std::vector<int> branchSums(TreeNode* root);

void branchSumsHelper(TreeNode* root,int runningSum,std::vector<int>&results);
