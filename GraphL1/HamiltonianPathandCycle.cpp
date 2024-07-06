#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr, int wt) : src(src), nbr(nbr), wt(wt) {}
};

// Function to add an edge to the graph
void addEdge(vector<Edge>* graph, int src, int nbr, int wt) {
    graph[src].push_back(Edge(src, nbr, wt));
    graph[nbr].push_back(Edge(nbr, src, wt)); // Assuming undirected graph
}

// Function to perform Hamiltonian path and cycle calculation
void h(vector<Edge>* graph, int src, unordered_set<int>& visited, string psf, int originalSrc) {
    if (visited.size() == graph->size() - 1) {
        cout << psf;

        bool containsCycle = false;
        for (Edge& e : graph[src]) {
            if (e.nbr == originalSrc) {
                containsCycle = true;
                break;
            }
        }

        if (containsCycle) {
            cout << "*" << endl;
        } else {
            cout << "." << endl;
        }

        return;
    }

    visited.insert(src);
    for (Edge& e : graph[src]) {
        if (visited.find(e.nbr) == visited.end()) {
            h(graph, e.nbr, visited, psf + to_string(e.nbr), originalSrc);
        }
    }
    visited.erase(src);
}

int main() {
    int vtces = 6; // Number of vertices
    //int edges = 7; // Number of edges

    // Create the graph using adjacency list representation
    vector<Edge>* graph = new vector<Edge>[vtces];

    // Add edges to the graph
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 3, 40);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 10);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 2);
    addEdge(graph, 2, 4, 3);

    int src = 0; // Source vertex

    // Perform Hamiltonian path and cycle calculation
    unordered_set<int> visited;
    h(graph, src, visited, to_string(src), src);

    delete[] graph; // Deallocate memory

    return 0;
}
