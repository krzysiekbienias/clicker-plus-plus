#include "graphs/graph_interview_mode.hpp"
#include "std_aliases.hpp"

using namespace stl;


GraphLC buildGraph(int n,const vector<vector<int>>& vecRep) {
    GraphLC g(n);
    for (auto & item:vecRep) {
        Vertex u=item[0]-1;
        Vertex v=item[1]-1;
        int w=item[2];
    g[u].push_back({v,w});
    g[v].push_back({u,w});
    }
    return g;
}