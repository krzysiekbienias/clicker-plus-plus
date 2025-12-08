#include "std_aliases.hpp"
#include "math_and_geometry/computational_geometry.hpp"

using namespace stl;
using namespace str;



int crossProduct(const Point2D & u, const Point2D& v){
    return u.x*v.y-u.y*v.x;
}
