#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int v;
    int wt;

     Edge(int nbr, int weight) {
        this->v = nbr;
        this->wt = weight;
    }
};

struct CompareEdge {
    bool operator()(const Edge& e1, const Edge& e2) {
        return e1.wt > e2.wt; // Min-Heap based on edge weight
    }
};

int main() {
    int vtces = 7;
    int edges = 8;
    vector<vector<Edge>> graph(vtces);

    vector<vector<int>> hardcoded_edges = {
        {0, 1, 10},
        {1, 2, 10},
        {2, 3, 10},
        {0, 3, 40},
        {3, 4, 2},
        {4, 5, 3},
        {5, 6, 3},
        {4, 6, 8}
    };

    for (auto& edge : hardcoded_edges) {
        int v1 = edge[0];
        int v2 = edge[1];
        int wt = edge[2];
        graph[v1].emplace_back(v2, wt);
        graph[v2].emplace_back(v1, wt);
    }

    int ans = 0;
    priority_queue<Edge, vector<Edge>, CompareEdge> pq;
    vector<bool> vis(vtces, false);
    pq.push(Edge(0, 0)); // Start with any vertex (0 in this case) with 0 weight

    while (!pq.empty()) {
        Edge rem = pq.top();
        pq.pop();

        if (vis[rem.v]) {
            continue;
        }
        vis[rem.v] = true;
        ans += rem.wt;

        for (Edge nbr : graph[rem.v]) {
            if (!vis[nbr.v]) {
                pq.push(nbr);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
