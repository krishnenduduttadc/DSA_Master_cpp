#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> dijkstra(int V, vector<vector<vector<int>>> &adj, int S)
{
    vector<int> ans(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, S));

    while (!pq.empty())
    {
        pair<int, int> rem = pq.top(); // (weight so far, vertex)
        pq.pop();

        int wsf = rem.first;
        int vtx = rem.second;

        if (ans[vtx] != INT_MAX)
            continue;

        ans[vtx] = wsf;

        for (vector<int> &edge : adj[vtx])
        {
            int nbr = edge[0];
            int wt = edge[1];

            if (ans[nbr] == INT_MAX)
            {
                pq.push(make_pair(wsf + wt, nbr));
            }
        }
    }

    return ans;
}

int main()
{
    int V = 6;
    vector<vector<vector<int>>> adj(V);
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({3, 3});
    adj[3].push_back({4, 2});
    adj[4].push_back({5, 5});

    int sourceVertex = 0;
    vector<int> shortestDistances = dijkstra(V, adj, sourceVertex);

    cout << "Shortest distances from vertex " << sourceVertex << ": " << endl;
    for (int i = 0; i < V; i++)
    {
        cout << "Vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
