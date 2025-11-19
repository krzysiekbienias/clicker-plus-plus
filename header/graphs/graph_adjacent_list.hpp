#pragma once

#include "std_aliases.hpp"

using namespace stl;

class Graph {


public:
    using Vertex =string;
    using Weight =int;

    struct Edge {
        string to;
        int weight;
    };

    explicit Graph(bool directed =true);

    bool addVertex( const Vertex& v);
    void addEdge(const Vertex & u ,const Vertex & v,Weight w=1);

    vector<Vertex> getVertices() const;
    const vector<Edge>& getNeighbors(const Vertex &v) const;
    size_t vertexCount()const;

    vector<Vertex> bfs(const Vertex& start) const;
    vector<Vertex> dfs(const Vertex& start) const;

    bool hasCycle(vector<string>& cycleOut) const;

    void printAdjList(std::ostream& os=std::cout) const;

    unordered_map<Vertex,Weight> dijkstra(Vertex start);

private:
    bool m_directed{true};
    unordered_map<Vertex,vector<Edge>> m_adjList;
};