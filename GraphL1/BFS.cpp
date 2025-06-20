#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<vector<int>>& adj, int v, int s) {
    deque<int> q;
    vector<bool> visited(v, false);
    
    q.push_back(s);
    visited[s] = true;

    while (!q.empty()) {
        int rem = q.front();
        q.pop_front();
        
        cout << rem << " ";

        for (int nbr : adj[rem]) {
            if (!visited[nbr]) {
                visited[nbr] = true;
                q.push_back(nbr);
            }
        }
    }
    cout << endl; // Print newline after traversal
}

int main() {
    int V = 7;
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 3, 4);

    cout << "Following is Breadth First Traversal: \n";
    bfs(adj, V, 0);

    return 0;
}
