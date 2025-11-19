#include <algorithm>

#include "graphs/graph_adjacent_list.hpp"
#include "std_aliases.hpp"

using namespace stl;

//constructor
Graph::Graph(bool directed):m_directed(directed) {}


bool Graph::addVertex(const string &v) {
    // try emplace returns the pair<iterator, bool> so the second is a bool everything fine
    return m_adjList.try_emplace(v,vector<Edge>{}).second;
}

void Graph::addEdge(const string& u, const string& v,int weight) {
    addVertex(u);
    addVertex(v);
    m_adjList[u].push_back(Edge{v,weight});
    //it handles automatic connection in both directions
    if (!m_directed) m_adjList[v].push_back(Edge{u,weight});
}

vector<string> Graph::getVertices() const {
    vector<string> vertices;
    vertices.reserve(m_adjList.size());
    for (const auto &[k,_]:m_adjList) {
        vertices.push_back(k);
    }
    return vertices;
}
// PERFORMANCE: return by const reference to avoid copying potentially large
// adjacency lists; ensures O(1) access while preventing external modification.
const vector<Graph::Edge>& Graph::getNeighbors(const string& v)const {
    static const vector<Edge> neighbors;//dummy vector of edges to hold neighbors.
    auto it=m_adjList.find(v);
    return (it==m_adjList.end()) ? neighbors:it->second;
    //it->second is vector as well!
}

size_t Graph::vertexCount() const {
    return m_adjList.size();
}

vector<string> Graph::dfs(const string & start) const {
    vector<string> order;
    auto it=m_adjList.find(start);
    if (it==m_adjList.end()) return order;

    unordered_set<string> visited;
    vector<string> stack{start};

    while (!stack.empty()) {
        string u=stack.back();
        stack.pop_back();
        if (!visited.insert(u).second) continue;
        order.push_back(u);
        const auto neighbors=getNeighbors(u);
        for (auto it =neighbors.rbegin();it!=neighbors.rend();++it) {
            const string& v=it->to;
            if (!visited.count(v)) {
                stack.push_back(v);
            }
        }
    }
return order;
}

std ::vector<string>Graph::bfs(const string& start)const{
    vector<string> order;
    auto it=m_adjList.find(start);
    if(it==m_adjList.end()) return order;

    unordered_set<string>visited;
    queue<string> q;

    visited.insert(start);
    q.push(start);

    while (!q.empty()){
        auto u=q.front();
        q.pop();
        order.push_back(u);
        const auto & neighbors=getNeighbors(u);
        for(const auto& e: neighbors){
            const string& w=e.to;
            if (visited.insert(w).second) {
                q.push(w);
            }
        }
    }
    return order;
}

enum{UNVISITED=0,VISITING=1,VISITED=2};

bool Graph::hasCycle(vector<string>& cycleOut) const{
    unordered_map<string,int> state;
    unordered_map<string,string> parent; //parent[child]=parentNode
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
            auto targetVertex =v.to;//DEBUG structured binding
            if(!state.count(targetVertex)) state[targetVertex]=UNVISITED;
        }
    }
    std::function<bool(const string&)> dfsCycle=[&](const string& u)->bool{
        state[u]=VISITING;
        //get from outer function neighbours
        const auto neighbors= getNeighbors(u);
        for (const auto& e:neighbors){
            const string &v=e.to;
            if(state[v]==UNVISITED){
                parent[v]=u;//remember how we get to v
                if(dfsCycle(v)) return true;

            }
            else if (state[v]==VISITING){

                //back-edge for active path->we have cycle
                vector<string> back;
                auto x=u;
                back.push_back(u);
                while (x!=v){
                    x=parent[x];
                    back.push_back(x);
                }
                reverse(back.begin(),back.end());
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