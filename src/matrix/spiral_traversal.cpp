#include "std_aliases.hpp"

using namespace stl;

//please take a look that sometimes we might use std::vector or vector.

vector<int> spiralTraverse(std::vector<std::vector<int>> array){
    int top=0;
    int bottom=(int)array.size()-1;
    int left=0;
    int right=(int)array[0].size()-1;
    vector<int> result;
    while (top<=bottom && left<=right){
        //1 top from left corner :left->right
        for (int j=left;j<=right;++j)
            result.push_back(array[top][j]);
        top++;
        //2 right: from right bottom->down
        for (int i=top;i<=bottom;++i)
            result.push_back(array[i][right]);
        --right;
        if (top<=bottom) {
            for (int j = right; j >= left; --j)
                result.push_back(array[bottom][j]);
            --bottom;
        }
        if(left<=right){
            for (int i=bottom;i>=top;--i)
                result.push_back(array[i][left]);
            ++left;
        }
        }
    return result;
}

