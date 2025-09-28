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

std::vector<std::string> Graph::dfs(const std::string & start) const {
    std::vector<std::string> order;
    auto it=m_adjList.find(start);
    if (it==m_adjList.end()) return order;

    std::unordered_set<std::string> visited;
    std::vector<std::string> stack{start};

    while (!stack.empty()) {
        std::string u=stack.back();
        stack.pop_back();
        if (!visited.insert(u).second) continue;
        order.push_back(u);
        const auto neighbors=getNeighbors(u);
        for (auto it =neighbors.rbegin();it!=neighbors.rend();++it) {
            if (!visited.count(*it)) stack.push_back(*it);
        }
    }
return order;
}

std ::vector<std::string>Graph::bfs(const std::string& start)const{
    std::vector<std::string> order;
    auto it=m_adjList.find(start);
    if(it==m_adjList.end()) return order;

    std::unordered_set<std::string>visited;
    std::queue<std::string> q;

    visited.insert(start);
    q.push(start);

    while (!q.empty()){
        auto u=q.front();
        q.pop();
        order.push_back(u);
        for(const auto& w: getNeighbors(u)){
            if(visited.insert(w).second) q.push(w);
        }
    }
    return order;
}

enum{UNVISITED=0,VISITING=1,VISITED=2};

bool Graph::hasCycle(std::vector<std::string>& cycleOut) const{
    std::unordered_map<std::string,int> state;
    std::unordered_map<std::string,std::string> parent; //parent[child]=parentNode
    state.reserve(m_adjList.size()*2);
    //1) Initiate states for all vertexes that are keys
    for  (const auto & [u,_]:m_adjList){
        auto keyVertex=u;//DEBUG structured binding
        state[u]=UNVISITED;
    }


    //2) Make sure that also vertexes that are in neighbours are in state map
    for (const auto & [u,_]:m_adjList){
        auto originVertex =u;//DEBUG
        const auto neighbors= getNeighbors(u);
        for (const auto &v:neighbors){
            auto targetVertex =v;//DEBUG structured binding
            if(!state.count(v)) state[v]=UNVISITED;
        }
    }
    std::function<bool(const std::string&)> dfsCycle=[&](const std::string& u)->bool{
        state[u]=VISITING;
        //get from outer function neighbours
        const auto neighbors= getNeighbors(u);
        for (const auto& v:neighbors){

            if(state[v]==UNVISITED){
                parent[v]=u;//remember how we get to v
                if(dfsCycle(v)) return true;

            }
            else if (state[v]==VISITING){

                //back-edge for active path->we have cycle
                std::vector<std::string> back;
                auto x=u;
                back.push_back(u);
                while (x!=v){
                    x=parent[x];
                    back.push_back(x);
                }
                std::reverse(back.begin(),back.end());
                back.push_back(v);
                cycleOut=std::move(back);
                return true;
            }

        }
        state[u]=VISITED;
        return false;
    };
    for (const auto&[u,st]:state){
        if(st == UNVISITED){
            if (dfsCycle(u)) return true;
        }
    }
    return false;
}