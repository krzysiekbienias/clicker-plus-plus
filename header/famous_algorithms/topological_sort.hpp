#pragma once
#include "std_aliases.hpp"

using namespace stl;

using Vertex=int;
using AdjList=unordered_map<Vertex,vector<Vertex>>;
using InDegreeMap=unordered_map<Vertex,int>;

vector<int> topologicalSort(const vector<int>& jobs,
                            const vector<vector<int>>& deps);