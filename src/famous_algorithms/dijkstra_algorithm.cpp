#include <std_aliases.hpp>
#include <famous_algorithms/dijkstra_algorithm.hpp>


using namespace stl;

AdjMat buildAdjMat(vector<vector<vector<int>>> edges){
    AdjMat res;
    vector<EdgeAlgoExpert> ve;

    for (Vertex u=0;u< edges.size();u++){
        vector<vector<int>>& vWeight=edges[u];
        vector<EdgeAlgoExpert>& outVec=res[u];
        for (vector<int> & item:vWeight){
            int to=item[0];
            int weight=item[1];
            EdgeAlgoExpert e{to,weight};
            outVec.push_back(e);
        }

        }
    return res;
}

// Implement your dijkstra_algorithm logic here.
vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
    int startingDistance=INT_MAX;

   auto adjlist= buildAdjMat(edges);
    unordered_map<int,int> distanceMap ;
    unordered_set<int> visited;
    for ( Vertex u=0;u<edges.size();++u) {
        distanceMap[u]=startingDistance;
    }
    distanceMap[0]=0;
    return {};

}


