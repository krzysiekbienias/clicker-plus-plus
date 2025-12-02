#pragma once

class TreeNode {
public:
    int m_value;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    //constructor

    explicit TreeNode(int value) {
        this->m_value = value;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    //destructor
    ~TreeNode() {
        delete left;
        delete right;
    }
    //block default copy
    TreeNode(const TreeNode &) = delete;
    //block default assignment
    TreeNode &operator=(const TreeNode &) = delete;

    //use when you want to create BinaryTree with parent pointer
    TreeNode* addLeftChild(int value) {
        auto *child =new TreeNode(value);
        child->parent =this;
        this->left=child;
        return child;
    }

    TreeNode* addRightChild(int value) {
        auto *child =new TreeNode(value);
        child->parent =this;
        this->right=child;
        return child;
    }
};