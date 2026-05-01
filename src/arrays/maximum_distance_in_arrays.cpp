#include <vector>



int maxDistance(std::vector<std::vector<int>>& arrays) {
    int curMin = arrays[0].front();
    int curMax = arrays[0].back();
    int result = 0;

    for (int i = 1; i < arrays.size(); i++) {
        // porównanie 1: curMax vs front aktualnej tablicy
        int prevMaxCurrentMin = curMax-arrays[i].front();

        // porównanie 2: back aktualnej tablicy vs curMin
        int currentMaxPrevMin = arrays[i].back()-curMin;

        result=std::max(result,std::max(prevMaxCurrentMin,currentMaxPrevMin));
        // zaktualizuj curMin i curMax
        curMin = std::min(curMin,arrays[i].front());
        curMax = std::max(curMax,arrays[i].back());
    }

    return result;
}