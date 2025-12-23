#pragma once
#include "std_aliases.hpp"

using namespace stl;

using Vertex=int;

struct Edge {
    Vertex to;
    int w;
};


using GraphLC = vector<vector<Edge>>;

GraphLC buildGraph(int n,const vector<vector<int>>& vecRep);