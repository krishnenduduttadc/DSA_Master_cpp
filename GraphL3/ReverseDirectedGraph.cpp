#include <iostream>
#include <vector>
using namespace std;

class ReverseDirectedGraph {
public:
    static vector<vector<int>> reverseDirectedGraph(const vector<vector<int>>& adj, int V) {
        vector<vector<int>> reversedAdj(V + 1);

        for (int i = 0; i <= V; ++i) {
            for (int j : adj[i]) {
                reversedAdj[j].push_back(i);
            }
        }

        return reversedAdj;
    }

    static void printGraph(const vector<vector<int>>& graph, int V) {
        for (int i = 1; i <= V; ++i) {
            for (int j : graph[i]) {
                cout << i << " -> " << j << endl;
            }
        }
    }
};

int main() {
    int V = 5;
    vector<vector<int>> adj(V + 1);

    adj[1].push_back(3);
    adj[1].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(5);

    vector<vector<int>> reversedAdj = ReverseDirectedGraph::reverseDirectedGraph(adj, V);

    cout << "Reversed Graph:" << endl;
    ReverseDirectedGraph::printGraph(reversedAdj, V);

    return 0;
}
