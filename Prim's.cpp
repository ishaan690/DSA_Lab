#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int from, to, weight;
};

// Find the parent of a node in DSU
int findParent(int node, vector<int>& parent) {
    if (node != parent[node])
        parent[node] = findParent(parent[node], parent);
    return parent[node];
}

// Union by rank in DSU
void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

// Kruskal's Algorithm
void kruskalAlgorithm(int vertices, vector<Edge>& edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(vertices), rank(vertices, 0);
    for (int i = 0; i < vertices; i++)
        parent[i] = i;

    vector<Edge> mst; // Store edges of MST
    int totalWeight = 0;

    for (const Edge& edge : edges) {
        if (findParent(edge.from, parent) != findParent(edge.to, parent)) {
            mst.push_back(edge);
            totalWeight += edge.weight;
            unionSets(edge.from, edge.to, parent, rank);
        }
    }

    // Print the MST
    cout << "Edges in the MST:\n";
    for (const Edge& edge : mst) {
        cout << edge.from << " - " << edge.to << " (Weight: " << edge.weight << ")\n";
    }
    cout << "Total Weight of MST: " << totalWeight << "\n";
}

int main() {
    int vertices, edgesCount;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edgesCount;

    vector<Edge> edges;
    cout << "Enter the edges (from, to, weight):\n";
    for (int i = 0; i < edgesCount; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back({from, to, weight});
    }

    kruskalAlgorithm(vertices, edges);
    return 0;
}
