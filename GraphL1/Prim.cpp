#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; 

int primMST(int V, vector<vector<pii>>& adj) {
    vector<bool> inMST(V, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq; 
    int mstWeight = 0;  
    pq.push({0, 0});
    
    while (!pq.empty()) {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (inMST[u] == true) {
            continue;
        }
        inMST[u] = true;
        mstWeight += w;
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (inMST[v] == false) {
                pq.push({weight, v});
            }
        }
    }
    return mstWeight;
}

int main() {
    
    int V = 4; // Number of vertices
    int E = 5; // Number of edges

    
    vector<vector<pii>> adj(V);
    
    // Hardcoded edges (u, v, w)
    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});
    
    adj[0].push_back({2, 6});
    adj[2].push_back({0, 6});
    
    adj[0].push_back({3, 5});
    adj[3].push_back({0, 5});
    
    adj[1].push_back({3, 15});
    adj[3].push_back({1, 15});
    
    adj[2].push_back({3, 4});
    adj[3].push_back({2, 4});

    int mstWeight = primMST(V, adj);
    cout << mstWeight << endl;
    return 0;
}
