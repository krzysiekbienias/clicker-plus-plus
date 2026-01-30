#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

/*          |
 *          |
 *          |
 *          |
 *          |_ _ _ _ _ _ _ _
 *The most
 */


double mostDistance(vector<vector<int>> coordinates) {
    double dist=0;
    int minX =INT_MAX;
    int maxX=INT_MIN;

    int minY=INT_MAX;
    int maxY=INT_MIN;
    for (const auto & c:coordinates)
    {
        maxX=std::max(maxX,c[0]);
        minX=std::min(minX,c[0]);

        maxY=std::max(maxY,c[1]);
        minY=std::min(minY,c[1]);
    }


    long long dist_x=maxX-minX;
    long long dist_y=maxY-minY;

    long long maxAbsX=std::max(std::llabs(minX),std::llabs(maxX));
    long long maxAbsY=std::max(std::llabs(minY),std::llabs(maxY));
    double dist_xy=std::sqrt(1.0*maxAbsX*maxAbsX+1.0*maxAbsY*maxAbsY);
    dist=std::max({static_cast<double>(dist_x),static_cast<double>(dist_y),dist_xy});
    return dist;
}

