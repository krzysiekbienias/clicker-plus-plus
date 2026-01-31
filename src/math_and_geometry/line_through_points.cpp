#include<vector>
#include "math_and_geometry/line_through_points.hpp"
#include <map>
#include<numeric> //for


// Implement your line_through_points logic here.


static std::vector<Point> toPoint(const std::vector<std::vector<int>>& points)
{
    std::vector<Point> result;
    result.reserve(points.size());
    for (const auto& point : points)
    {
        result.emplace_back(point[0], point[1]);
    }
    return result;
}


int lineThroughPoints(const std::vector<std::vector<int>>& points)
{
    if (points.empty()) return 0;
    if (points.size()==2) return 2;
    std::vector<Point>vecPoints = toPoint(points);
    int maxCount = 0;
    for (int i = 0; i < points.size(); ++i)
    {
        std::map<std::pair<int, int>, int> slopeCount;
        const Point& focal = vecPoints[i];
        //the focal point is a fixed point with respect to the point we compare the rest.

        int localMax = 0;
        for (int j = 0; j < vecPoints.size(); ++j)
        {
            if (i == j) continue; //🤓 focal will produce a 0/0 slope that is undefined.
            //we add focal as an extra point in line with the rest we find
            int yDistance = vecPoints[j].y - focal.y; //dy
            int xDistance = vecPoints[j].x - focal.x; //dx
            int gcd = std::gcd(yDistance, xDistance); //to avoid, floating-point error
            //slope will be store as normalized rational number to avoid comparing doubles
            yDistance /= gcd;
            xDistance /= gcd;
            //Normalize slop sign ⚠️
            if (xDistance < 0)
            {
                xDistance = -xDistance;
                yDistance = -yDistance;
            }
            slopeCount[{xDistance, yDistance}]++;
        }
        for (const auto& [slope,count] : slopeCount)
        {
            localMax = std::max(localMax, count); //+1 to not miss the focal point
        }
        maxCount = std::max(maxCount, localMax + 1);
    }
    return maxCount;
}
