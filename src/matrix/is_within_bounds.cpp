#include "matrix/is_within_bounds.hpp"

// Implement your is_within_bounds logic here.
bool isWithinBounds(int r, int c, const std::vector<std::vector<int>>& matrix){
    int nbRows=0;
    int nbCols=0;
    if (!matrix.empty()) {
        nbRows=(int)matrix.size();
        nbCols=(int)matrix[0].size();
    }
    return (r>=0 && r<nbRows) && (c>=0 &&c<nbCols);
}
