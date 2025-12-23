#pragma once
#include "std_aliases.hpp"

using namespace stl;
using namespace str;

using Vertex=int;

struct Edge {
    Vertex to;
    int w;

    friend ostream &operator<<(ostream &os, const Edge &e) {
        return os << "--(" << e.w << ")--" << e.to;
    }
};


using GraphLC = vector<vector<Edge>>;

GraphLC buildGraph(int n,const vector<vector<int>>& vecRep);