#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int hourglassSum(vector<vector<int>> arr) {
    int maxSum=INT_MIN;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int tempSum=arr[i][j]+arr[i][j+1]+arr[i][j+2]
                                +arr[i+1][j+1]
                        +arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
            maxSum=std::max(tempSum,maxSum);

        }
    }
    return maxSum;

}