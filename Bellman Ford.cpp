#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Structure to represent an edge
struct Edge {
    int from, to, weight;
};

// Bellman-Ford Algorithm
bool bellmanFord(int vertices, int edgesCount, vector<Edge>& edges, int source) {
    vector<int> distance(vertices, INT_MAX); // Distance array
    distance[source] = 0;                   // Distance to source is 0

    // Relax all edges |V| - 1 times
    for (int i = 0; i < vertices - 1; i++) {
        for (const auto& edge : edges) {
            if (distance[edge.from] != INT_MAX && 
                distance[edge.from] + edge.weight < distance[edge.to]) {
                distance[edge.to] = distance[edge.from] + edge.weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        if (distance[edge.from] != INT_MAX &&
            distance[edge.from] + edge.weight < distance[edge.to]) {
            cout << "Graph contains a negative-weight cycle.\n";
            return false; // Negative-weight cycle found
        }
    }

    // Print the shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << "\t" << (distance[i] == INT_MAX ? "INF" : to_string(distance[i])) << "\n";
    }

    return true; // No negative-weight cycle
}

int main() {
    int vertices, edgesCount;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edgesCount;

    vector<Edge> edges;

    cout << "Enter the edges (from, to, weight):\n";
    for (int i = 0; i < edgesCount; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back({from, to, weight});
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    if (!bellmanFord(vertices, edgesCount, edges, source)) {
        cout << "The graph contains a negative-weight cycle. Shortest paths cannot be determined.\n";
    }

    return 0;
}
