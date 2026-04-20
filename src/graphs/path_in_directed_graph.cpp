#include "std_aliases.hpp"

using namespace stl;

int pathInDirectedGraph(int A, const vector<vector<int>>& B) {
    if (A==1) return 1;

    //1. build adj list
    vector<vector<int>> adj(A+1); //<-- we need A+1 becasue we start from 1 index zero exists but is not used.
    for (const auto &e:B) {
        int u=e[0], v=e[1];
        if (1<=u&&u<=A && 1<=v&& v<=A)
            adj[u].push_back(v);
    }

    //2. Iterative DFS
    vector<char> visited(A+1,false); //<--- visited as a vector because vertexes are 1,2,3...A
    vector<int> st;
    st.push_back(1);
    visited[1]=true;
    while (!st.empty()) {
        int u=st.back();
        st.pop_back();
        if (u==A) return 1;
        for (int v:adj[u]) {
            if (!visited[v]) {
                visited[v]=true;
                st.push_back(v);
            }
        }
    }
    return 0;
}