#pragma once
# include<string>
# include<vector>
#include <unordered_map>

class Graph {
private:
    bool m_directed;
    std::unordered_map<std::string,std::vector<std::string>> m_adjList;

public:
    explicit Graph(bool directed =false);

    bool addVertex( const std::string& v);
    void addEdge(const std::string & u ,const std::string & v);

    std::vector<std::string> getVertices() const;
    const std::vector<std::string>& getNeighbors(const std::string &v) const;
    size_t vertexCount()const;

    std::vector<std::string> bfs(const std::string& start) const;
    std::vector<std::string> dfs(const std::string& start) const;





};