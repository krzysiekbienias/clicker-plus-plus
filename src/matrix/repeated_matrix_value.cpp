# include "std_aliases.hpp"

using namespace stl;


vector<int> repeatedMatrixValues(vector<vector<int>> matrix) {
    vector<int> result;
    int r= matrix.size();
    int c=matrix[0].size();
    unordered_map<int,int> rowCount;


    unordered_map<int,int> colCount;
    for (int i=0;i<r;++i) {
        unordered_set<int> rowSeen;
        for (int j=0;j<c;++j) {
            if (rowSeen.insert(matrix[i][j]).second) {
                rowCount[matrix[i][j]]++;
            }
        }
    }
    for (int j=0;j<c;++j) {
        unordered_set<int> colSeen;
        for (int i=0;i<r;++i) {
            if (colSeen.insert(matrix[i][j]).second) {
                colCount[matrix[i][j]]++;
            }

        }
    }

    for (const auto &[k,v]  : rowCount) {
        if (rowCount[k]==r && colCount[k]==c) result.push_back(k);

    }
    return result;
}