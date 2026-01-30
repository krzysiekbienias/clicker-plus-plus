#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int diagonalDifferenceTwoLoops(const std::vector<std::vector<int>>& arr)
{
    int s = arr.size();
    int mainDiagonal = 0;
    int secondDiagonal = 0;
    int res = 0;

    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < s; ++j)
        {
            if (i == j)
            {
                mainDiagonal += arr[i][j];
            }
            if (i + j == s - 1)
            {
                secondDiagonal += arr[i][j];
            }
        }
    }
    res = abs(mainDiagonal - secondDiagonal);
    return res;
}

int diagonalDifference(const std::vector<std::vector<int>>& arr)
{
    int n = static_cast<int>(arr.size());
    long long mainDiagonal = 0;
    long long secondDiagonal = 0;

    for (int i = 0; i < n; ++i)
    {
        mainDiagonal  += arr[i][i];
        secondDiagonal += arr[i][n - 1 - i];
    }

    return static_cast<int>(std::abs(mainDiagonal - secondDiagonal));
}