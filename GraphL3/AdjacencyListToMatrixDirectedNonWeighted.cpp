#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> convertToAdjacencyMatrix(vector<vector<int>>& adj, int V) {
    vector<vector<int>> adjacencyMatrix(V + 1, vector<int>(V + 1, 0));

    for (int i = 1; i <= V; ++i) {
        for (int j : adj[i]) {
            adjacencyMatrix[i][j] = 1;
        }
    }

    return adjacencyMatrix;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V + 1);

    adj[1].push_back(3);
    adj[1].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(5);

    vector<vector<int>> adjacencyMatrix = convertToAdjacencyMatrix(adj, V);

    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
