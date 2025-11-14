#pragma once

class TreeNode {
    public:
        int m_value;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;
        //constructor

        explicit TreeNode(int value) {
            this->m_value = value;
            left = nullptr;
            right = nullptr;
            parent= nullptr;
        }

        //destructor
        ~TreeNode() {
            delete left;
            delete right;
        }
};