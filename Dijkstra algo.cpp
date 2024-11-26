#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// A structure to represent a weighted edge in the graph
struct Edge {
    int to, weight;
};

// Function to perform Dijkstra's Algorithm
vector<int> dijkstra(int source, const vector<vector<Edge>>& graph) {
    int n = graph.size();  // Number of vertices
    vector<int> dist(n, INT_MAX);  // Distance array
    dist[source] = 0;

    // Min-heap priority queue (distance, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        // If the distance in the queue is outdated, skip it
        if (currentDist > dist[currentNode]) continue;

        // Explore neighbors
        for (const Edge& edge : graph[currentNode]) {
            int nextNode = edge.to;
            int newDist = currentDist + edge.weight;

            // Relaxation step
            if (newDist < dist[nextNode]) {
                dist[nextNode] = newDist;
                pq.push({newDist, nextNode});
            }
        }
    }

    return dist;  // Return the shortest distances from the source
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    // Create the adjacency list representation of the graph
    vector<vector<Edge>> graph(vertices);
    cout << "Enter the edges (from, to, weight):\n";
    for (int i = 0; i < edges; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});  // Add this line for an undirected graph
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    // Find the shortest paths using Dijkstra's Algorithm
    vector<int> distances = dijkstra(source, graph);

    // Output the shortest distances
    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < distances.size(); i++) {
        cout << "Vertex " << i << ": ";
        if (distances[i] == INT_MAX)
            cout << "INF";
        else
            cout << distances[i];
        cout << "\n";
    }

    return 0;
}
