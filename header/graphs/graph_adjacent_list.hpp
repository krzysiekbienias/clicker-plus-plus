#pragma once

#include "std_aliases.hpp"

using namespace stl;
using namespace str;

class Graph {
public:
    using Vertex = string;
    using Weight = int;

    struct Edge {
        string to;
        int weight;

        friend ostream &operator<<(ostream &os, const Edge &e) {
            return os << "--(" << e.weight << ")-->" << e.to;
        }
    };

    static constexpr int INF =1'000'000'000;

    struct DistanceMatrix {
        vector<Vertex> indexToVertex;
        unordered_map<Vertex,int> vertexToIndex;
        vector<vector<int>> distMat;

        friend std::ostream& operator<< (ostream& os, const DistanceMatrix& dm);
    };

    explicit Graph(bool directed = true);

    bool addVertex(const Vertex &v);

    void addEdge(const Vertex &u, const Vertex &v, Weight w = 1);

    vector<Vertex> getVertices() const;

    const vector<Edge> &getNeighbors(const Vertex &v) const;

    size_t vertexCount() const;

    vector<Vertex> bfs(const Vertex &start) const;

    vector<Vertex> dfs(const Vertex &start) const;

    bool hasCycle(vector<string> &cycleOut) const;

    unordered_map<Vertex, Weight> dijkstra(Vertex start);

    void printAdjList(std::ostream &os = std::cout) const;

    void printDijkstraResult(const Vertex &source,
                             const std::unordered_map<Vertex, int> &distanceMap,
                             std::ostream &os=std::cout) const;

    vector<Vertex> topologicalSortKahn()const;
    DistanceMatrix buildDistanceMatrix() const;

    DistanceMatrix floydWarshall()const;
private:

    bool m_directed{true};
    unordered_map<Vertex, vector<Edge>> m_adjList;

    unordered_map<Vertex, int> calculateInDegreeMap() const; //better to prepare a map of all degrees in one shot

};
