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

        // If we have already processed this vertex, continue.
        if (ans[vtx] != INT_MAX)
            continue;

        // Update the shortest distance to this vertex.
        ans[vtx] = wsf;

        // Traverse all neighboring vertices.
        for (vector<int> &edge : adj[vtx])
        {
            int nbr = edge[0];
            int wt = edge[1];

            // If the neighboring vertex has not been visited, add it to the priority queue.
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
    // Adding edges to the graph
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({3, 3});
    adj[3].push_back({4, 2});
    adj[4].push_back({5, 5});

    // Source vertex for Dijkstra's algorithm
    int sourceVertex = 0;

    // Call Dijkstra's algorithm
    vector<int> shortestDistances = dijkstra(V, adj, sourceVertex);

    // Print the shortest distances
    cout << "Shortest distances from vertex " << sourceVertex << ": " << endl;
    for (int i = 0; i < V; i++)
    {
        cout << "Vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
