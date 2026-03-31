#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
std::vector<int> minOperationsToGatherInOneBox(const std::string& boxes) {
    int n=boxes.size();
    vector<int> results(n);

    //from left-->right
    int balls=0;
    int moves=0;
    for (int i = 0; i < n; ++i)
    {   results[i]+=moves;
        if (boxes[i]=='1')
        {
            balls++;
        }
        moves+=balls;
    }

    //reset
    balls=0;
    moves=0;
    //right -->left
    for (int i = n-1; i >=0 ; --i)
    {
        results[i]+=moves;
        if (boxes[i]=='1')
        {
            balls++;
        }
        moves+=balls;
    }
    return results;

}