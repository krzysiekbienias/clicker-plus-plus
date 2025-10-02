#pragma once

#include<vector>

// Declare your remove_island interface here.

std::vector<std::vector<int>> removeIslands(std::vector<std::vector<int>> matrix);
void dfsRemoveIslands(std::vector<std::vector<int>> &matrix,int row,int col);