#include <algorithm>

#include "graphs/graph_adjacent_list.hpp"
#include "std_aliases.hpp"
#include "utils/print_utils.hpp"
#include "utils/print_utils_templates.hpp"

using namespace stl;

//constructor
Graph::Graph(bool directed):m_directed(directed) {}


bool Graph::addVertex(const Vertex &v) {
    // try emplace returns the pair<iterator, bool> so the second is a bool everything fine
    return m_adjList.try_emplace(v,vector<Edge>{}).second;
}

void Graph::addEdge(const Vertex& u, const Vertex& v,Weight weight) {
    addVertex(u);
    addVertex(v);
    m_adjList[u].push_back(Edge{v,weight});
    //it handles automatic connection in both directions
    if (!m_directed)
        m_adjList[v].push_back(Edge{u,weight});
}

vector<Graph::Vertex> Graph::getVertices() const {
    vector<Vertex> vertices;
    vertices.reserve(m_adjList.size());
    for (const auto &[k,_]:m_adjList) {
        vertices.push_back(k);
    }
    return vertices;
}
// PERFORMANCE: return by const reference to avoid copying potentially large
// adjacency lists; ensures O(1) access while preventing external modification.
const vector<Graph::Edge>& Graph::getNeighbors(const Vertex& v)const {
    static const vector<Edge> neighbors;//dummy vector of edges to hold neighbors.
    auto it=m_adjList.find(v);
    return (it==m_adjList.end()) ? neighbors:it->second;
    //it->second is vector as well!
}

size_t Graph::vertexCount() const {
    return m_adjList.size();
}

vector<Graph::Vertex> Graph::dfs(const Vertex & start) const {
    vector<Vertex> order;
    auto it=m_adjList.find(start);
    if (it==m_adjList.end()) return order;

    unordered_set<Vertex> visited;
    vector<Vertex> stack{start};

    while (!stack.empty()) {
        Vertex u=stack.back();
        stack.pop_back();
        if (!visited.insert(u).second) continue;
        order.push_back(u);
        const auto neighbors=getNeighbors(u);
        for (auto it =neighbors.rbegin();it!=neighbors.rend();++it) {
            const Vertex& v=it->to;
            if (!visited.count(v)) {
                stack.push_back(v);
            }
        }
    }
return order;
}

std ::vector<Graph::Vertex>Graph::bfs(const Vertex& start)const{
    vector<Vertex> order;
    auto it=m_adjList.find(start);
    if(it==m_adjList.end()) return order;

    unordered_set<Vertex>visited;
    queue<Vertex> q;

    visited.insert(start);
    q.push(start);

    while (!q.empty()){
        auto u=q.front();
        q.pop();
        order.push_back(u);
        const auto & neighbors=getNeighbors(u);
        for(const auto& e: neighbors){
            const Vertex& w=e.to;
            if (visited.insert(w).second) {
                q.push(w);
            }
        }
    }
    return order;
}

enum{UNVISITED=0,VISITING=1,VISITED=2};

bool Graph::hasCycle(vector<Vertex>& cycleOut) const{
    unordered_map<Vertex,int> state;
    unordered_map<Vertex,Vertex> parent; //parent[child]=parentNode
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
    std::function<bool(const string&)> dfsCycle=[&](const Vertex& u)->bool{
        state[u]=VISITING;
        //get from outer function neighbours
        const auto neighbors= getNeighbors(u);
        for (const auto& e:neighbors){
            const Vertex &v=e.to;
            if(state[v]==UNVISITED){
                parent[v]=u;//remember how we get to v
                if(dfsCycle(v)) return true;

            }
            else if (state[v]==VISITING){

                //back-edge for active path->we have cycle
                vector<Vertex> back;
                Vertex x=u;
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

unordered_map<Graph::Vertex,int> Graph::dijkstra(Vertex source) {
    int startingDistance=INT_MAX;
    unordered_map<Vertex,int> distanceMap;
    unordered_set<Vertex> visited;
    for (const auto&[u,_]:m_adjList) {
        distanceMap[u]=startingDistance;
    }
    distanceMap[source]=0;
    //DEBUG
    //print_utils::printUnorderedMap(distanceMap);

    using State=std::pair<int,Vertex>;
    //we need min_heap
    MinHeap<State> pq;
    pq.emplace(0,source);
    while (!pq.empty()) {
        //snap for analysis
        auto [dist,u]=pq.top();
        //remove from top
        pq.pop();
        // check if vertex from top has been visited.
        if (visited.count(u))
            continue;
        visited.insert(u);
        //collect neighbours for current vertex u
        const auto & neighbours=getNeighbors(u);
        for (const auto & e:neighbours) {
            Vertex v=e.to;
            Weight w=e.weight;
            int cand =distanceMap[u]+w;
            if (cand<distanceMap[v]) {
                distanceMap[v]=cand;
                pq.emplace(cand,v);
            }
        }
    }
    return distanceMap;
}


void Graph::printAdjList(std::ostream& os) const {
    if (m_adjList.empty()) {
        os << "# Graph is empty\n";
        return;
    }

    os << "# directed: " << (m_directed ? "true" : "false") << "\n";

    // 1) zbieramy wszystkie wierzchołki (klucze) do wektora
    std::vector<Vertex> keys;
    keys.reserve(m_adjList.size());
    for (const auto& [u, _] : m_adjList) {
        keys.push_back(u);
    }

    // 2) sortujemy klucze
    std::sort(keys.begin(), keys.end());

    // 3) wypisujemy w porządku rosnącym po kluczu
    for (const auto& u : keys) {
        os << u << ": ";

        const auto& neighbors = m_adjList.at(u);

        bool first = true;
        for (const auto& e : neighbors) {
            if (!first) {
                os << " ";
            }
            first = false;
            os << e.to << "(" << e.weight << ")";
        }

        os << "\n";
    }
}