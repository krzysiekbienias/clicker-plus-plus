# include<string>
# include<vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include "graphs/graph_adjacent_list.hpp"

//constructor
Graph::Graph(bool directed):m_directed(directed) {}

bool Graph::addVertex(const std::string &v) {
    // try emplace returns the pair<iterator, bool> so the second is a bool everything fine
    return m_adjList.try_emplace(v,std::vector<std::string>{}).second;
}

void Graph::addEdge(const std::string& u, const std::string& v) {
    addVertex(u);
    addVertex(v);
    m_adjList[u].push_back(v);
    //it handles automatic connection in both directions
    if (!m_directed) m_adjList[v].push_back(u);
}

std::vector<std::string> Graph::getVertices() const {
    std::vector<std::string> vertices;
    vertices.reserve(m_adjList.size());
    for (const auto &[k,_]:m_adjList) {
        vertices.push_back(k);
    }
    return vertices;
}
// PERFORMANCE: return by const reference to avoid copying potentially large
// adjacency lists; ensures O(1) access while preventing external modification.
const std::vector<std::string>& Graph::getNeighbors(const std::string& v)const {
    static const std::vector<std::string> neighbors;
    auto it=m_adjList.find(v);
    return (it==m_adjList.end()) ? neighbors:it->second;
    //it->second is vector as well!
}

size_t Graph::vertexCount() const {
    return m_adjList.size();
}
