#include <iostream>
#include <vector>
#include <stack>
#include <string>

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

    Pair(int v, string psf) {
        this->v = v;
        this->psf = psf;
    }
};

void addEdge(vector<Edge>* graph, int src, int nbr) {
    graph[src].push_back(Edge(src, nbr));
    graph[nbr].push_back(Edge(nbr, src)); // Assuming undirected graph
}

int main() {
    int vtces = 6; // Number of vertices

    vector<Edge>* graph = new vector<Edge>[vtces];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 2, 4);

    int src = 0; // Source vertex

    bool* visited = new bool[vtces](); // Initialize all elements to false
    stack<Pair> st;
    st.push(Pair(src, to_string(src)));

    while (!st.empty()) {
        Pair rem = st.top();
        st.pop();

        if (visited[rem.v]) {
            continue;
        }
        visited[rem.v] = true;
        cout << rem.v << "@" << rem.psf << endl;

        for (Edge& e : graph[rem.v]) {
            if (!visited[e.nbr]) {
                st.push(Pair(e.nbr, rem.psf + to_string(e.nbr)));
            }
        }
    }

    delete[] graph; // Deallocate memory
    delete[] visited;

    return 0;
}
