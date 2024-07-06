#include <iostream>
#include <vector>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr, int wt) : src(src), nbr(nbr), wt(wt) {}
};

// Function to perform DFS and find connected components
void dfs(vector<Edge>* graph, int src, vector<int>& component, vector<bool>& visited) {
    visited[src] = true;
    component.push_back(src);
    for (Edge& e : graph[src]) {
        if (!visited[e.nbr]) {
            dfs(graph, e.nbr, component, visited);
        }
    }
}

int main() {
    int vtces = 6; // Number of vertices
    int edges = 7; // Number of edges

    // Define the edge information statically
    vector<Edge> edgeInfo = {
        Edge(0, 1, 10),
        Edge(0, 2, 10),
        Edge(1, 2, 10),
        Edge(2, 3, 10),
        Edge(3, 4, 10),
        Edge(4, 5, 10),
        Edge(5, 3, 10)
    };

    // Create the graph using adjacency list representation
    vector<Edge>* graph = new vector<Edge>[vtces];

    // Add edges to the graph
    for (Edge& e : edgeInfo) {
        graph[e.src].push_back(e);
        graph[e.nbr].push_back(Edge(e.nbr, e.src, e.wt)); // Adding reverse edge for undirected graph
    }

    vector<vector<int>> connectedComponents;

    // Array to track visited vertices
    vector<bool> visited(vtces, false);

    // Finding all connected components using DFS
    for (int v = 0; v < vtces; ++v) {
        if (!visited[v]) {
            vector<int> component;
            dfs(graph, v, component, visited);
            connectedComponents.push_back(component);
        }
    }

    // Outputting the connected components
    cout << "Connected Components:" << endl;
    for (vector<int>& component : connectedComponents) {
        for (int v : component) {
            cout << v << " ";
        }
        cout << endl;
    }

    delete[] graph; // Deallocate memory

    return 0;
}
