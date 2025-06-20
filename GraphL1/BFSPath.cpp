#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Edge {
    int src;
    int nbr;

    Edge(int src, int nbr) {
        this->src = src;
        this->nbr = nbr;
    }
};

struct Pair {
    int v;
    string psf;

    Pair(int v, string psf) : v(v), psf(psf) {}
};

void addEdge(vector<Edge>* graph, int v1, int v2) {
    graph[v1].push_back(Edge(v1, v2));
    graph[v2].push_back(Edge(v2, v1));
}

int main() {
    int vtces = 7; // Number of vertices
    vector<Edge>* graph = new vector<Edge>[vtces]; // Adjacency list of edges

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 0, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);
    addEdge(graph, 4, 6);

    int src = 0; // Source vertex for BFS

    deque<Pair> q; // Queue for BFS
    vector<bool> visited(vtces, false); // Array to mark visited vertices

    q.push_back(Pair(src, to_string(src))); // Pushing source vertex with path so far

    while (!q.empty()) {
        Pair rem = q.front();
        q.pop_front();

        if (visited[rem.v]) {
            continue;
        }
        visited[rem.v] = true;

        cout << rem.v << " " << rem.psf << endl; // Printing vertex and path so far

        for (Edge e : graph[rem.v]) {
            q.push_back(Pair(e.nbr, rem.psf + to_string(e.nbr))); // Adding adjacent vertices to queue
        }
    }

    delete[] graph; // Freeing dynamically allocated memory for graph
    return 0;
}
