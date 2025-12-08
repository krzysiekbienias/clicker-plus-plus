#include <std_aliases.hpp>
#include "math_and_geometry/computational_geometry.hpp"

using namespace stl;


bool checkStraightLine(vector<vector<int> > &coordinates) {
    vector<Point2D> vp;
    for (const auto &item: coordinates) {
        vp.push_back({item[0], item[1]});
    }
    if (coordinates.size() <= 2) return true;
    int n = vp.size();
    Point2D u = vp[0] - vp[1];
    for (int i = 2; i < n; ++i) {
        Point2D nextVec = vp[0] - vp[i];
        int nextCross = crossProduct(u, nextVec);
        if (nextCross != 0) return false;
    }
    return true;
}
