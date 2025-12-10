#include <std_aliases.hpp>
#include <famous_algorithms/dijkstra_algorithm.hpp>


using namespace stl;

AdjMat buildAdjMat(vector<vector<vector<int> > > edges) {
    AdjMat res;
    vector<EdgeAlgoExpert> ve;

    for (Vertex u = 0; u < edges.size(); u++) {
        vector<vector<int> > &vWeight = edges[u];
        vector<EdgeAlgoExpert> &outVec = res[u];
        for (vector<int> &item: vWeight) {
            int to = item[0];
            int weight = item[1];
            EdgeAlgoExpert e{to, weight};
            outVec.push_back(e);
        }
    }
    return res;
}

// Implement your dijkstra_algorithm logic here.
vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int> > > edges) {
    int startingDistance = INT_MAX;

    auto adjlist = buildAdjMat(edges);
    unordered_map<int, int> distanceMap;
    unordered_set<int> visited;
    for (Vertex u = 0; u < edges.size(); ++u) {
        distanceMap[u] = startingDistance;
    }
    distanceMap[start] = 0;

    using State = pair<int, Vertex>;
    priority_queue<State, vector<State>, std::greater<State>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto item = pq.top();
        pq.pop();
        Vertex u = item.second;
        if (visited.count(u)) {
            continue;
        }
        visited.insert(u);

        if (distanceMap[u] == startingDistance) //INF-> we cannot get to u and there is no sense to make relaxation
            continue;

        const auto &neighbours = adjlist[u];
        for (const auto &neighbour: neighbours) {
            Vertex v = neighbour.to;
            int w = neighbour.weight;
            int cand = distanceMap[u] + w;
            if (cand < distanceMap[v]) {
                distanceMap[v] = cand;
                pq.emplace(cand, v);
            }
        }
    }
    //and we build a result
    int n = edges.size();
    vector<int> res(n, -1);
    for (int v = 0; v < n; ++v) {
        if (distanceMap[v] != startingDistance) {
            res[v] = distanceMap[v];
        }
    }
    return res;
}
