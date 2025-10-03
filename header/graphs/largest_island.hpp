#pragma once
#include <vector>
#include <matrix/is_within_bounds.hpp>

// we need following functions
// 1. matrix bounds to check bounds -> imported from matrix folder
// 2. dfs to calculate size of each island (0)
// 3. label each chunk of the land into unordered_map<label,size>

//Grid Scan we will use to edge cases so to make prescan if we have area that consist only with 0s or 1s
struct GridScan {
    int land=0;
    int water=0;
};

//this function returns size of area
int dfsIslandsSize(std::vector<std::vector<int>> &worldGrid,int r,int col,int label);
std::unordered_map<int,int> labelLand(std::vector<std::vector<int>> &matrixGrid);

GridScan prescanGrid(const std::vector<std::vector<int>> &matrix);
int largestIsland(std::vector<std::vector<int>> worldGrid);