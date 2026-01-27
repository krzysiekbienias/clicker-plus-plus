#pragma once

#include <string>
#include <vector>

int determinant (std::vector<std::vector<int>>& matrix);

bool checkPivotBareiss(std::vector<std::vector<long long>> & matrix,int& swapCounter,int k);


int determinantBareiss (std::vector<std::vector<long long>> & matrix);