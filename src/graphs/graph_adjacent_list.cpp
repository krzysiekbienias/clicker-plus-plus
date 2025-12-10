#include <algorithm>

#include "graphs/graph_adjacent_list.hpp"
#include "std_aliases.hpp"
#include "utils/print_utils.hpp"
#include "utils/print_utils_templates.hpp"

using namespace stl;

//constructor
Graph::Graph(bool directed) : m_directed(directed) {
}


bool Graph::addVertex(const Vertex &v) {
    // try emplace returns the pair<iterator, bool> so the second is a bool everything fine
    return m_adjList.try_emplace(v, vector<Edge>{}).second;
}

void Graph::addEdge(const Vertex &u, const Vertex &v, Weight weight) {
    addVertex(u);
    addVertex(v);
    m_adjList[u].push_back(Edge{v, weight});
    //it handles automatic connection in both directions
    if (!m_directed)
        m_adjList[v].push_back(Edge{u, weight});
}

vector<Graph::Vertex> Graph::getVertices() const {
    vector<Vertex> vertices;
    vertices.reserve(m_adjList.size());
    for (const auto &[k,_]: m_adjList) {
        vertices.push_back(k);
    }
    return vertices;
}

// PERFORMANCE: return by const reference to avoid copying potentially large
// adjacency lists; ensures O(1) access while preventing external modification.
const vector<Graph::Edge> &Graph::getNeighbors(const Vertex &v) const {
    static const vector<Edge> neighbors; //dummy vector of edges to hold neighbors.
    auto it = m_adjList.find(v);
    return (it == m_adjList.end()) ? neighbors : it->second;
    //it->second is vector as well!
}

size_t Graph::vertexCount() const {
    return m_adjList.size();
}

vector<Graph::Vertex> Graph::dfs(const Vertex &start) const {
    vector<Vertex> order;
    auto it = m_adjList.find(start);
    if (it == m_adjList.end()) return order;

    unordered_set<Vertex> visited;
    vector<Vertex> stack{start};

    while (!stack.empty()) {
        Vertex u = stack.back();
        stack.pop_back();
        if (!visited.insert(u).second) continue;
        order.push_back(u);
        const auto neighbors = getNeighbors(u);
        for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
            const Vertex &v = it->to;
            if (!visited.count(v)) {
                stack.push_back(v);
            }
        }
    }
    return order;
}

std::vector<Graph::Vertex> Graph::bfs(const Vertex &start) const {
    vector<Vertex> order;
    auto it = m_adjList.find(start);
    if (it == m_adjList.end()) return order;

    unordered_set<Vertex> visited;
    queue<Vertex> q;

    visited.insert(start);
    q.push(start);

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        order.push_back(u);
        const auto &neighbors = getNeighbors(u);
        for (const auto &e: neighbors) {
            const Vertex &w = e.to;
            if (visited.insert(w).second) {
                q.push(w);
            }
        }
    }
    return order;
}

enum { UNVISITED = 0, VISITING = 1, VISITED = 2 };

bool Graph::hasCycle(vector<Vertex> &cycleOut) const {
    unordered_map<Vertex, int> state;
    unordered_map<Vertex, Vertex> parent; //parent[child]=parentNode
    state.reserve(m_adjList.size() * 2);
    //1) Initiate states for all vertexes that are keys
    for (const auto &[u,_]: m_adjList) {
        auto keyVertex = u; //DEBUG structured binding
        state[u] = UNVISITED;
    }


    //2) Make sure that also vertexes that are in neighbours are in state map
    for (const auto &[u,_]: m_adjList) {
        auto originVertex = u; //DEBUG
        const auto neighbors = getNeighbors(u);
        for (const auto &v: neighbors) {
            auto targetVertex = v.to; //DEBUG structured binding
            if (!state.count(targetVertex)) state[targetVertex] = UNVISITED;
        }
    }
    std::function<bool(const string &)> dfsCycle = [&](const Vertex &u)-> bool {
        state[u] = VISITING;
        //get from outer function neighbours
        const auto neighbors = getNeighbors(u);
        for (const auto &e: neighbors) {
            const Vertex &v = e.to;
            if (state[v] == UNVISITED) {
                parent[v] = u; //remember how we get to v
                if (dfsCycle(v)) return true;
            } else if (state[v] == VISITING) {
                //back-edge for active path->we have cycle
                vector<Vertex> back;
                Vertex x = u;
                back.push_back(u);
                while (x != v) {
                    x = parent[x];
                    back.push_back(x);
                }
                reverse(back.begin(), back.end());
                back.push_back(v);
                cycleOut = std::move(back);
                return true;
            }
        }
        state[u] = VISITED;
        return false;
    };
    for (const auto &[u,st]: state) {
        if (st == UNVISITED) {
            if (dfsCycle(u)) return true;
        }
    }
    return false;
}

unordered_map<Graph::Vertex, int> Graph::dijkstra(Vertex source) {
    int startingDistance = INT_MAX;
    unordered_map<Vertex, int> distanceMap;
    unordered_set<Vertex> visited;
    for (const auto &[u,_]: m_adjList) {
        distanceMap[u] = startingDistance;
    }
    distanceMap[source] = 0;
    //DEBUG
    //print_utils::printUnorderedMap(distanceMap);

    using State = std::pair<int, Vertex>;
    //we need min_heap
    MinHeap<State> pq;
    pq.emplace(0, source);
    while (!pq.empty()) {
        //snap for analysis
        auto & item  = pq.top();
        int dist=item.first;
        Vertex u =item.second;

        //remove from top
        pq.pop();
        // check if vertex from the top has been visited.
        if (visited.count(u))
            continue;
        visited.insert(u);
        //collect neighbours for current vertex u
        const auto &neighbours = getNeighbors(u);
        for (const auto &e: neighbours) {
            Vertex v = e.to;
            Weight w = e.weight;
            int cand = distanceMap[u] + w;
            if (cand < distanceMap[v]) {
                distanceMap[v] = cand;
                pq.emplace(cand, v);
            }
        }
    }
    return distanceMap;
}

unordered_map<Graph::Vertex, int> Graph::calculateInDegreeMap() const {
    std::unordered_map<Vertex,int> inDegree;
    inDegree.reserve(2*m_adjList.size());
    for (const auto&[u,edges]:m_adjList) {
        inDegree.try_emplace(u,0);
        for (const auto &e:edges) {
            const Vertex& v=e.to;
            if (!inDegree.count(v)) {
                inDegree[v]=0;
            }
            inDegree[v]+=1;
        }
    }
    return inDegree;
}

vector<Graph::Vertex> Graph::topologicalSortKahn()const {
    vector<Vertex> order;
    //it only may be performed on a directed graph
    if (!m_directed) {
        return order;
    }

    auto inDegree=calculateInDegreeMap();

    queue<Vertex> q;
    for (const auto & item:inDegree) {
        Vertex u=item.first;
        int deg=item.second;
        if (deg==0) {
            q.push(u);
        }
    }
    while (!q.empty()) {
        Vertex u=q.front();
        q.pop();
        order.push_back(u);
        //now we visit neighbors of u and decrease in degree of neighbors
        const auto & neighbours=getNeighbors(u);
        for (const auto & neighbour:neighbours) {
            const Vertex v=neighbour.to;
            auto it=inDegree.find(v);
            if (it==inDegree.end()) continue;
            it->second--;
            if (it->second==0) {
                q.push(v);
            }
        }
    }
    //check if there is no cycle
    if (order.size()!=inDegree.size()) {
        order.clear();
    }
    return order;
}


void Graph::printAdjList(std::ostream &os) const {
    if (m_adjList.empty()) {
        os << "# Graph is empty\n";
        return;
    }

    os << "# directed: " << (m_directed ? "true" : "false") << "\n";

    // 1) zbieramy wszystkie wierzchołki (klucze) do wektora
    std::vector<Vertex> keys;
    keys.reserve(m_adjList.size());
    for (const auto &[u, _]: m_adjList) {
        keys.push_back(u);
    }

    // 2) sprawdzamy, czy wszystkie wierzchołki są "liczbowe"
    auto isNumeric = [](const std::string& s) {
        if (s.empty()) return false;
        return std::all_of(s.begin(), s.end(), [](unsigned char c) {
            return std::isdigit(c);
        });
    };

    bool allNumeric = std::all_of(keys.begin(), keys.end(),
                                  [&](const Vertex& v){ return isNumeric(v); });

    // 3) sortujemy:
    //    - numerycznie (po wartości) jeśli np. "1","2","10"
    //    - leksykograficznie jeśli np. "A","B","C"
    if (allNumeric) {
        std::sort(keys.begin(), keys.end(),
                  [](const Vertex& a, const Vertex& b) {
                      return std::stoi(a) < std::stoi(b);
                  });
    } else {
        std::sort(keys.begin(), keys.end());
    }

    // 4) wypisujemy w porządku rosnącym po kluczu
    for (const auto &u: keys) {
        os << u << ":\n";

        const auto &neighbors = m_adjList.at(u);

        for (const auto &e: neighbors) {
            os << "  " << e << "\n"; // leverage operator<< for Edge
        }
        os << "\n";
    }
}


void Graph::printDijkstraResult(const Vertex& source,
                                const std::unordered_map<Vertex,int>& distanceMap,
                                std::ostream& os) const
{
    if (distanceMap.empty()) {
        os << "# Dijkstra result is empty\n";
        return;
    }

    os << "# Dijkstra distances from source: " << source << "\n";

    // 1) zbierz wszystkie wierzchołki
    std::vector<Vertex> keys;
    keys.reserve(distanceMap.size());
    for (const auto& [v, _] : distanceMap) {
        keys.push_back(v);
    }

    // 2) sprawdź, czy wszystkie są numeryczne ("1","2","10")
    auto isNumeric = [](const std::string& s) {
        if (s.empty()) return false;
        return std::all_of(s.begin(), s.end(), [](unsigned char c) {
            return std::isdigit(c);
        });
    };

    bool allNumeric = std::all_of(keys.begin(), keys.end(),
                                  [&](const Vertex& v){ return isNumeric(v); });

    // 3) sortowanie: numeryczne vs leksykograficzne
    if (allNumeric) {
        std::sort(keys.begin(), keys.end(),
                  [](const Vertex& a, const Vertex& b) {
                      return std::stoi(a) < std::stoi(b);
                  });
    } else {
        std::sort(keys.begin(), keys.end());
    }

    // 4) wypisanie wyników
    for (const auto& v : keys) {
        os << "  " << v << " : ";
        int dist = distanceMap.at(v);
        if (dist == INT_MAX) {
            os << "INF";
        } else {
            os << dist;
        }
        os << "\n";
    }

    os << "=============================================\n";
}
