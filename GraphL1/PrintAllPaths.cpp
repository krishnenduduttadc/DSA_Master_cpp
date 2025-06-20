#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int src;
    int nbr;
    int wt;

    Edge(int s, int n, int w) {
        src = s;
        nbr = n;
        wt = w;
    }
};

void addEdge(vector<Edge>* graph, int src, int nbr, int wt);
void printAllPaths(vector<Edge>* graph, int src, int dest, vector<bool>& visited, string psf);

int main() {
    int vtces = 6; // Number of vertices

    vector<Edge>* graph = new vector<Edge>[vtces];

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 3, 40);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 10);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 2);
    addEdge(graph, 2, 4, 3);

    int src = 0;   // Source vertex
    int dest = 5;  // Destination vertex

    vector<bool> visited(vtces, false);

    printAllPaths(graph, src, dest, visited, to_string(src));

    return 0;
}

void addEdge(vector<Edge>* graph, int src, int nbr, int wt) {
    graph[src].emplace_back(src, nbr, wt);
    graph[nbr].emplace_back(nbr, src, wt);
}

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
