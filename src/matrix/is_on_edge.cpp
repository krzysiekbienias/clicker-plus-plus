#include <vector>
#include "matrix/is_within_bounds.hpp"

bool isOnTheEdge(int r, int c, const std::vector<std::vector<int>>& matrix){
    int nbRows=0;
    int nbCols=0;
    if (!matrix.empty()) {
        nbRows=(int)matrix.size();
        nbCols=(int)matrix[0].size();
    }
    if (r<0 || c<0 || r>=nbRows || c>=nbCols)
        throw :: std::out_of_range("Indexes are out of the matrix bounds.");
    return (r==0 || c==0 || r==nbRows-1 || c==nbCols-1);
}