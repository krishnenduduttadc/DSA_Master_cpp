#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> convertToAdjacencyList(int adjacencyMatrix[][6], int V) {
    vector<vector<int>> adj(V + 1);

    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }

    return adj;
}

int main() {
    int V = 5;
    int adjacencyMatrix[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    vector<vector<int>> adj = convertToAdjacencyList(adjacencyMatrix, V);

    for (int i = 1; i <= V; ++i) {
        cout << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
