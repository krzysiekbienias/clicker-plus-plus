#include <std_aliases.hpp>


using namespace stl;

#include "binary_tree/binary_tree_simple.hpp"
BinaryTree* buildMinHeightBst(vector<int> array,int left,int right) {
    while (left>right) return nullptr;

    int mid=left+(right-left)/2;
    BinaryTree * root=new BinaryTree(array[mid]);
    root->left=buildMinHeightBst(array,left,mid-1);
    root->right=buildMinHeightBst(array, mid+1,right);
    return root;
}


BinaryTree* minHeightBst(vector<int> array) {
    if (array.empty()) return nullptr;
    int n=array.size();
    return buildMinHeightBst(array,0,n-1);


}