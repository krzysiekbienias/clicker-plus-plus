#include <vector>

std::vector<int> searchInSortedMatrix(std::vector<std::vector<int>> matrix, int target) {
    int rowNb=matrix.size();
    int colNb=matrix[0].size();

    int r=0;
    int c=colNb-1;
    while (r<rowNb && c>=0)
    {
        if (matrix[r][c]==target)
        {
            return {r,c};
        }
        if (matrix[r][c]>target)
        {
            c--;
        }
        if (matrix[r][c]<target)
        {
            r++;
        }
    }

    return {-1,-1};
}
