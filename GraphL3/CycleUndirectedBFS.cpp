#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Node {
public:
    int first, second;
    Node(int first, int second) {
        this->first = first;
        this->second = second;
    }
};

class CycleUndirectedBFS {
public:
    bool checkForCycle(vector<vector<int>>& adj, int s, vector<bool>& vis, vector<int>& parent) {
        queue<Node> q;  // BFS
        q.push(Node(s, -1));
        vis[s] = true;

        // until the queue is empty
        while (!q.empty()) {
            // source node and its parent node
            int node = q.front().first;
            int par = q.front().second;
            q.pop();

            // go to all the adjacent nodes
            for (int it : adj[node]) {
                if (!vis[it]) {
                    q.push(Node(it, node));
                    vis[it] = true;
                }
                // if adjacent node is visited and is not its own parent node
                else if (it != par) return true;
            }
        }

        return false;
    }

    // function to detect cycle in an undirected graph
    bool isCycle(int V, vector<vector<int>>& adj) {
        vector<bool> vis(V, false);
        vector<int> parent(V, -1);

        for (int i = 0; i < V; i++)
            if (!vis[i])
                if (checkForCycle(adj, i, vis, parent))
                    return true;

        return false;
    }
};

int main() {
    vector<vector<int>> adj(4);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);

    CycleUndirectedBFS obj;
    bool ans = obj.isCycle(4, adj);
    if (ans) {
        cout << "cycle exists" << endl;
    } else {
        cout << "cycle does not exist" << endl;
    }

    return 0;
}
