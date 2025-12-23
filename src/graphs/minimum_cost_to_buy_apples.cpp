#include "std_aliases.hpp"
#include "graphs/minimum_cost_to_buy_apples.hpp"
using namespace stl;
using namespace str;


Graph buildGraph(int n, const vector<vector<int> > &vecRep) {
    Graph g(n + 1);
    for (auto &item: vecRep) {
        Vertex u = item[0];
        Vertex v = item[1];
        int w = item[2];
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    return g;
}

vector<ll> dijkstra(Vertex start, const Graph &g) {
    int n = g.size();
    vector<ll> dist(n, INF);
    dist[start] = 0;
    // monitor distance in max heap
    using State = std::pair<ll, Vertex>;
    priority_queue<State, vector<State>, std::greater<> > pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue; // te jest
        for (auto &e: g[u]) {
            Vertex v = e.to;
            int weight = e.w;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
    // we ignore dist[0] and g[0]
}

ll calculateCost(int dist, int k, int price) {
    ll totalCost = dist + price + dist * k;
    return totalCost;
}

vector<long long> minCost(int n, const vector<vector<int> > &roads,
                          const vector<int> &appleCost, int k) {
    Graph g = buildGraph(n, roads);
    // for (int u = 1; u <= n; ++u) {
    //     cout << u << ": ";
    //     for (const Edge& e : g[u]) {
    //         cout << e << " ";
    //     }
    //     cout << '\n';
    // }
    vector<ll> res;
    for (int u = 1; u <= n; ++u) {
        vector<ll> shortestDist = dijkstra(u, g);
        // cout << "Starting with vertex " << u << '\n';
        // for (int j=1;j<=n;++j){

        //     cout<<shortestDist[j]<<" ";

        // }
        // cout<<'\n';
        ll localMin = INF;
        for (int i = 1; i < shortestDist.size(); i++) {
            if (shortestDist[i] == INF)
                continue;
            ll temp;
            temp = calculateCost(shortestDist[i], k, appleCost[i - 1]);
            localMin = std::min(localMin, temp);
        }
        res.push_back(localMin);
    }

    return res;
}
