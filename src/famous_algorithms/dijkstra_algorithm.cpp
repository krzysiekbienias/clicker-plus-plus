#include <std_aliases.hpp>
#include <famous_algorithms/dijkstra_algorithm.hpp>


using namespace stl;


// Implement your dijkstra_algorithm logic here.
vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
    int startingDistance=INT_MAX;
    using Vertex = int;
    vector<EdgeAlgoExpert> ve;
    unordered_map<int,int> distanceMap ;
    unordered_set<int> visited;
    for ( const auto & neighbours :edges) {
        for ( const auto &item : neighbours)
            ve.push_back({item[0],item[1]});
    }
    for ( Vertex u=0;u<edges.size();++u) {
        distanceMap[u]=startingDistance;
    }
    distanceMap[0]=0;
    return {};

}


