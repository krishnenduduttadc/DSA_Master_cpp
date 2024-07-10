#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int dest;
    int weight;

     Edge(int d, int wt) {
        dest = d;
        weight = wt;
    }
};

vector<vector<Edge>> convertToWeightedAdjacencyList(int adjmat[][6], int V) {
    vector<vector<Edge>> adj(V + 1);

    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (adjmat[i][j] != 0) {
                adj[i].push_back(Edge(j, adjmat[i][j]));
            }
        }
    }

    return adj;
}

int main() {
    int V = 5;
    int adjmat[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 2, 3, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0}
    };

    vector<vector<Edge>> weightedAdjacencyList = convertToWeightedAdjacencyList(adjmat, V);

    for (int i = 1; i <= V; ++i) {
        cout << i << ": ";
        for (Edge edge : weightedAdjacencyList[i]) {
            cout << "(" << edge.dest << ", " << edge.weight << ") ";
        }
        cout << endl;
    }

    return 0;
}
