#include <std_aliases.hpp>

using namespace stl;

int minimumOperations(vector<int>& nums) {
    int operationNumbers=0;
    for (int x :nums) {
        if (x%3!=0) operationNumbers++;
    }
    return operationNumbers;
}