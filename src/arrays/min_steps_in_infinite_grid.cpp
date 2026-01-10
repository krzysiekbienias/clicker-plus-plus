#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int minStepsInInfiniteGrid(vector<int> A, vector<int> B)
{   int minSum=0;
    int n=A.size();
    for (int i=1;i<n;i++)
    {
        int dist_i=std::max(abs(A[i]-A[i-1]),abs(B[i]-B[i-1]));
        minSum+=dist_i;
    }
    return minSum;
}