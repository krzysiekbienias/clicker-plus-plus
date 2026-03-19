#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;



// Implement your logic here.
int balancedTwoCityFlight(vector<std::vector<int>> &costs){
    std::sort(costs.begin(),costs.end(),[](const vector<int>& a,const vector<int>& b )
    {
       return (a[0]-a[1]<b[0]-b[1]);
    });

    int n=costs.size()/2; //no danger because there are 2n elements in costs
    int total = 0;

    for (int i = 0; i < n; ++i)
    {
        total+=costs[i][0]; //delegated to A
    }
    for (int i = n; i < 2*n; ++i)
    {
        total+=costs[i][1];
    }
    return total;
}