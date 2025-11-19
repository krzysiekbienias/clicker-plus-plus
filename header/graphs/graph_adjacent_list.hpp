#pragma once

#include "std_aliases.hpp"

using namespace stl;

class Graph {


public:
    struct Edge {
        string to;
        int weight;
    };

    explicit Graph(bool directed =true);

    bool addVertex( const string& v);
    void addEdge(const string & u ,const string & v,int weight=1);

    vector<std::string> getVertices() const;
    const vector<Edge>& getNeighbors(const string &v) const;
    size_t vertexCount()const;

    vector<string> bfs(const string& start) const;
    vector<string> dfs(const string& start) const;

    bool hasCycle(vector<string>& cycleOut) const;

    void printAdjList(std::ostream& os=std::cout) const;

    vector<string> dijkstra(string start);

private:
    bool m_directed{true};
    unordered_map<string,vector<Edge>> m_adjList;
};