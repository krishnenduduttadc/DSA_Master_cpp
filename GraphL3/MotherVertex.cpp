#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Recursive DFS function to visit all vertices reachable from src.
void dfs(vector<vector<int>>& adj, int src, vector<bool>& vis, stack<int>& st) {
    vis[src] = true;
    for (int nbr : adj[src]) {
        if (!vis[nbr]) {
            dfs(adj, nbr, vis, st);
        }
    }
    st.push(src); // Push vertex to stack after all reachable vertices are visited.
}

int findMotherVertex(int V, vector<vector<int>>& adj) {
    vector<bool> vis(V, false);
    stack<int> st;

    // Perform DFS to fill the stack with vertices in finishing order.
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(adj, i, vis, st);
        }
    }

    // Pop the last vertex from the stack which should be a potential mother vertex.
    int potentialMother = st.top();
    st.pop();

    // Reset visited array for another DFS to check if potentialMother is a mother vertex.
    fill(vis.begin(), vis.end(), false);
    dfs(adj, potentialMother, vis, st);

    // Check if all vertices are visited in the second DFS starting from potentialMother.
    for (int i = 0; i < V; i++) {
        if (!vis[i]) return -1; // If any vertex is not visited, potentialMother is not a mother vertex.
    }

    return potentialMother;
}

int main() {
    // Example graph representation using adjacency list
    int V = 7; // Number of vertices
    vector<vector<int>> adj(V);

    // Adding edges to the graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(5);
    adj[5].push_back(6);
    adj[6].push_back(4);

    // Finding the mother vertex
    int motherVertex = findMotherVertex(V, adj);

    if (motherVertex != -1) {
        cout << "A mother vertex is: " << motherVertex << endl;
    } else {
        cout << "No mother vertex found." << endl;
    }

    return 0;
}
