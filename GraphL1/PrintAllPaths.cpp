#include <iostream>
#include <vector>

using namespace std;

// Define the Edge structure
struct Edge {
    int src;
    int nbr;
    int wt;

    Edge(int s, int n, int w) : src(s), nbr(n), wt(w) {}
};

// Function prototypes
void addEdge(vector<Edge>* graph, int src, int nbr, int wt);
void printAllPaths(vector<Edge>* graph, int src, int dest, vector<bool>& visited, string psf);

int main() {
    int vtces = 6; // Number of vertices
    //int edges = 7; // Number of edges

    // Create the graph using vector of vectors
    vector<Edge>* graph = new vector<Edge>[vtces];

    // Add edges statically
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 3, 40);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 10);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 2);
    addEdge(graph, 2, 4, 3);

    int src = 0;   // Source vertex
    int dest = 5;  // Destination vertex

    // Array to track visited vertices
    vector<bool> visited(vtces, false);

    // Call the function to print all paths from src to dest
    printAllPaths(graph, src, dest, visited, to_string(src));

    return 0;
}

// Function to add an edge to the graph
void addEdge(vector<Edge>* graph, int src, int nbr, int wt) {
    graph[src].emplace_back(src, nbr, wt);
    graph[nbr].emplace_back(nbr, src, wt);
}

// Function to print all paths from src to dest
void printAllPaths(vector<Edge>* graph, int src, int dest, vector<bool>& visited, string psf) {
    if (src == dest) {
        cout << psf << endl;
        return;
    }

    visited[src] = true;
    for (Edge edge : graph[src]) {
        if (!visited[edge.nbr]) {
            printAllPaths(graph, edge.nbr, dest, visited, psf + to_string(edge.nbr));
        }
    }
    visited[src] = false;
}
