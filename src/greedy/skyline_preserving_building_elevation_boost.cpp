#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

int maxIncreaseKeepingSkyline(const std::vector<std::vector<int>>& grid)
{
    int possibleElevation{0};

    int n = grid.size();
    vector<int> maxRow;
    maxRow.reserve(n);
    vector<int> maxCol(n);
    for (const auto& row : grid)
    {
        maxRow.push_back(*max_element(row.begin(), row.end()));
    }
    for (int c = 0; c < n; ++c)
    {
        int mx = INT_MIN;
        for (int r = 0; r < n; ++r)
        {
            mx = std::max(mx, grid[r][c]);
        }
        maxCol[c] = mx;
    }
    int allowedHeight = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            allowedHeight = std::min(maxRow[i], maxCol[j]);
            possibleElevation = +allowedHeight - grid[i][j];
        }
    }
    return possibleElevation;
}
