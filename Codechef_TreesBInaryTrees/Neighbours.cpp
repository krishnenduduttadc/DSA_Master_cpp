#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, v;
    cin >> N >> v; // Read the number of nodes and the target node v

    vector < pair < int, int >> edges(N - 1); // To store the edges
    vector < vector < int >> adj(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int u, w;
        cin >> u >> w; // Read each edge
        edges[i] = {
            u,
            w
        }; // Store the edge

        adj[u].push_back(w);
        adj[w].push_back(u);
    }
    int neighbors = adj[v].size();
    cout << neighbors << endl;

}


/*
7 2
1 2
1 4
2 5
2 3
2 6
4 7


*/