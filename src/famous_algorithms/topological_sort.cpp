# include <std_aliases.hpp>
# include <famous_algorithms/topological_sort.hpp>

using namespace stl;


vector<int> topologicalSort(const vector<int>& jobs,
                            const vector<vector<int>>& deps) {
        AdjList adj;
        InDegreeMap inDegree;
        //initialise adjacent list and inDegree map from row vector data
        for (Vertex u:jobs) {
            adj[u]={};
            inDegree[u]=0;
        }
        //build adj list from input
        for (const auto &edge : deps) {
            Vertex from=edge[0];
            Vertex to=edge[1];
            adj[from].push_back(to);
            inDegree[to]+=1; //we increase inDegree
        }
        //create queue with Vertex of inDegree =0
        queue<Vertex> q;
        for (const auto & [v,deg]:inDegree) {
            if (deg==0) {
                q.push(v);
            }
        }

        // apply Kahn's
        vector<Vertex> order;
        while (!q.empty()) {
            Vertex u =q.front();
            q.pop();
            order.push_back(u);
            //adj[u] is vector so we may
            for (Vertex v:adj[u]) {
                inDegree[v]--;
                if (inDegree[v]==0) {
                    q.push(v);
                }
            }

        }
    if (order.size()!=jobs.size()) {
        return {}; //empty vector if there is a cycle in the graph
    }
    return order;

}