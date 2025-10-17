#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    size_t m_distance;
    size_t m_vertex;

    Edge() = default;
    Edge(size_t distance, size_t vertex)
        : m_distance{distance}, m_vertex{vertex}
    {}

    bool operator() (const Edge& a, const Edge& b) const {
        return a.m_distance > b.m_distance;
    }
};

const size_t INF {std::numeric_limits<int>::max()};
// using Edge = std::pair<size_t, size_t>;
using Graph = std::vector<std::vector<Edge>>;

struct DijkstraResult {
    std::vector<size_t> distance;
    std::vector<size_t> previous;
};

DijkstraResult dijkistra(size_t start, const Graph& graph) {
    std::vector<size_t> distances (graph.size(), INF); // distance to two nodes is infinite
    std::vector<size_t> prevList (graph.size(), INF); // distance to two nodes is infinite

    distances.at(start) = 0; // Distance from origin is zero

    // priority queue is a sorted Min-heap of (distance, vertex)
    std::priority_queue<Edge, std::vector<Edge>, Edge> pq;
    pq.emplace(0, start);

    while(!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();

        // std::cout << "distance: " << dist << " Node: " << node << " -> ";
        for(const auto& [weight, neighbor] : graph.at(node)) {
            if ((dist + weight) < distances[neighbor]) {
                // std::cout << neighbor << " ";
                distances[neighbor] = dist + weight;
                prevList[neighbor] = node;
                pq.push({distances[neighbor], neighbor});
            }
        }
        // std::cout << '\n';
    }
    return {distances, prevList};
}

int main() {
    // Graph adjacency list = { {weight, vertex}, ... }
    Graph graph = {
        {{3,2}, {2,5}},                         // 0 -> (3,2), (2,5)
        {{2,4}, {6,5}, {2,6}, {1,3}},           // 1 -> ...
        {{3,0}, {2,5}, {1,4}, {4,3}},           // 2
        {{4,2}, {1,1}},                         // 3
        {{1,2}, {2,1}, {3,5}},                  // 4
        {{2,0}, {2,2}, {3,4}, {6,1}, {5,6}},    // 5
        {{5,5}, {2,1}}                          // 6
    };


    size_t source {0};
    size_t dest {1};
    auto dist = dijkistra(source, graph);
  
    std::cout << "Shortest distances from vertex " << source << ":\n";
    for (size_t i = 0; i < graph.size(); ++i) {
        if (dist.distance[i] == INF)
            std::cout << i << ": INF\n";
        else
            std::cout << i << ": " << dist.distance[i] << "\n";
    }

    std::cout << "Route from vertex: " << dest << " to vertex: " << source << " is: \n";
    std::cout << dest << ", ";
    while(dist.previous[dest] != INF && dest <= dist.previous.size() && dest >= 0 ) {
        std::cout << dist.previous[dest] << ", ";
        dest = dist.previous[dest];
    }

    std::cout << '\n';
}

// Shortest distances from vertex 0:
// 0: 0
// 1: 6
// 2: 3
// 3: 7
// 4: 4
// 5: 2
// 6: 7
// Route from vertex: 1 to vertex: 0 is: 
// 1, 4, 2, 0, 