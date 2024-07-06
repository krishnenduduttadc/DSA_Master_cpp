#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int d;
    int wt;

    Edge(int d, int wt) : d(d), wt(wt) {}
};

vector<vector<int>> convertToAdjacencyMatrix(vector<vector<Edge>>& adj, int V) {
    vector<vector<int>> adjmat(V + 1, vector<int>(V + 1, 0));

    for (int i = 1; i <= V; ++i) {
        for (Edge e : adj[i]) {
            int j = e.d;
            int wt = e.wt;
            adjmat[i][j] = wt;
        }
    }

    return adjmat;
}

int main() {
    int V = 5;
    vector<vector<Edge>> adj(V + 1);

    adj[1].push_back(Edge(3, 2));
    adj[1].push_back(Edge(2, 1));
    adj[3].push_back(Edge(4, 3));
    adj[4].push_back(Edge(5, 4));

    vector<vector<int>> adjmat = convertToAdjacencyMatrix(adj, V);

    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
