#pragma once
#include <std_aliases.hpp>

using namespace stl;
using namespace str;

struct Point2D{
    int x;
    int y;

     Point2D operator - (const Point2D & other) const{
        return {x-other.x,y-other.y};
    }

    friend ostream& operator<<(ostream& os,const Point2D &p){
        return os <<"Point P(x,y)= "<<"("<<p.x<<", "<<p.y<<")";

    }
};

int crossProduct(const Point2D &u, const Point2D &v);
