
#include <vector>

#include "matrix/is_within_bounds.hpp"
#include "matrix/is_on_edge.hpp"
// Implement your remove_island logic here.

static constexpr std::array<std::pair<int,int>,4> directions{{ {-1,0}, {1,0}, {0,-1}, {0,1} }};

void dfsRemoveIslands(std::vector<std::vector<int>> &matrix,int row,int col) {
    matrix[row][col]=-1;
    for (auto & [dr,dc]:directions) {
        int newRow=row+dr;
        int newCol=col+dc;
        if (isWithinBounds(newRow,newCol,matrix)  && matrix[newRow][newCol]==1) {
            dfsRemoveIslands(matrix,newRow,newCol);
        }
    }

}

std::vector<std::vector<int>> removeIslands(std::vector<std::vector<int>> matrix) {

    for (int r=0;r<matrix.size();++r) {
        for (int c=0;c<matrix[0].size();++c) {
            if (isOnTheEdge(r,c,matrix) && matrix[r][c]==1)
            dfsRemoveIslands(matrix,r,c);
        }
    }

    for (int r=0;r<matrix.size();++r) {
        for (int c=0;c<matrix[0].size();++c) {
            if (matrix[r][c]==-1)
                matrix[r][c]=1;
            else if (matrix[r][c]==1)
                matrix[r][c]=0;
        }
    }

    return matrix;
}

