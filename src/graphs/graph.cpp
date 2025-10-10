
#include "graphs/graph_node.hpp"
#include "graphs/graph.hpp"
// Implement your graph logic here.


AbstractGraph::~AbstractGraph(){
    for (auto  & [ _ ,  node ] : m_nodes)
        delete node;
}

GraphNode* AbstractGraph::addNode(int id){
    if (!m_nodes.count(id)) {
        m_nodes[id]=new GraphNode(id);
    }
    return m_nodes[id];
}


void AbstractGraph::addEdge(int fromId, int toId, bool directed) {
    GraphNode* from = addNode(fromId);
    GraphNode* to = addNode(toId);
    from->addNeighbor(to);

    if (!directed) {
        to->addNeighbor(from);  // Mirror the edge for undirected graph
    }
}

void AbstractGraph::display(bool directed) const {
    std::unordered_set<std::string> printedEdges;

    for (const auto& [id, node] : m_nodes) {
        for (GraphNode* neighbor : node->getNeighbors()) {
            int from = id;
            int to = neighbor->getId();

            std::string edge;
            std::string arrow;

            if (directed) {
                edge = std::to_string(from) + "->" + std::to_string(to);
                arrow = "->";
            } else {
                // Normalize to avoid printing both directions
                int a = std::min(from, to);
                int b = std::max(from, to);
                edge = std::to_string(a) + "-" + std::to_string(b);
                arrow = "<->";
            }

            if (!printedEdges.count(edge)) {
                std::cout << from << " " << arrow << " " << to << '\n';
                printedEdges.insert(edge);
            }
        }
    }
}

void AbstractGraph::displayAdjacencyList(bool directed) const {
    std::cout << "+======================================+\n";
    std::cout << "| Adjacency List" << (directed ? " (Directed)" : " (Undirected)") << "         |\n";
    std::cout << "+======================================+\n";

    for (const auto& [id, node] : m_nodes) {
        std::cout << id << ": ";

        // Collect and sort for consistent output
        std::vector<int> neighbors;
        for (GraphNode* neighbor : node->getNeighbors()) {
            neighbors.push_back(neighbor->getId());
        }
        std::sort(neighbors.begin(), neighbors.end());

        for (int nid : neighbors)
            std::cout << nid << " ";
        std::cout << '\n';
    }
}

void AbstractGraph::dfs(int startId) const{
    if (!m_nodes.count(startId)) {
        std::cout<<"Start node not found.\n";
        return;
    }
    std::unordered_set<int> visited;
    dfsHelper(m_nodes.at(startId), visited);
}

void AbstractGraph::dfsHelper(GraphNode *node, std::unordered_set<int> &visited)const{
    if (!node||visited.count(node->getId())) {
        return ;
    }
    
    visited.insert(node->getId());
    std::cout<<"Visited: "<<node->getId()<<'\n';
    for (GraphNode* neighbor:node->getNeighbors())
        dfsHelper(neighbor, visited);
}

