# pragma once

#include "std_aliases.hpp"

using namespace stl;
using namespace str;

using Vertex = int;
using ll = long long;
static constexpr ll INF =1'000'000'000;
struct Edge {
    Vertex to;
    int w;

    friend ostream &operator<<(ostream &os, const Edge &e) {
        return os << "--(" << e.w << ")--" << e.to;
    }
};

using Graph = vector<vector<Edge>>;

vector<ll> dijkstra(Vertex start, const Graph& g);

ll calculateCost(int dist,int k,int price);

vector<long long> minCost(int n, const vector<vector<int>>& roads,
                          const vector<int>& appleCost, int k);