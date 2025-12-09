#pragma once
#include <std_aliases.hpp>

using namespace stl;

struct EdgeAlgoExpert{
    int to;
    int weight;
};

// Declare your dijkstra_algorithm interface here.
vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges);