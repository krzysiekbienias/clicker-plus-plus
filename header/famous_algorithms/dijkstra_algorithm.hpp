#pragma once
#include <std_aliases.hpp>

using namespace stl;

struct EdgeAlgoExpert{
    int to;
    int weight;
};

using Vertex = int;

using AdjMat=unordered_map<Vertex,vector<EdgeAlgoExpert>>;

AdjMat buildAdjMat(vector<vector<vector<int>>> edges);
// Declare your dijkstra_algorithm interface here.
vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges);