#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Prim
{
public:
    struct Pair
    {
        int distance;
        int node;

        Pair(int dist, int n)
        {
            distance = dist;
            node = n;
        }

        // Overloading the < operator to use Pair in priority queue
        bool operator<(const Pair &other) const
        {
            return distance > other.distance;
        }
    };

    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    static int spanningTree(int V, vector<vector<vector<int>>> &adj)
    {
        priority_queue<Pair> pq;

        vector<int> vis(V, 0); // 0 - not visited, 1 - visited
        pq.push(Pair(0, 0));   // Start with node 0, distance 0
        int sum = 0;

        while (!pq.empty())
        {
            int wt = pq.top().distance;
            int node = pq.top().node;
            pq.pop();

            if (vis[node] == 1)
                continue;
            vis[node] = 1; // Mark node as visited
            sum += wt;     // Add weight to MST sum

            // Traverse adjacent nodes
            for (int i = 0; i < adj[node].size(); ++i)
            {
                int adjNode = adj[node][i][0];
                int edgeWeight = adj[node][i][1];
                if (vis[adjNode] == 0)
                {
                    pq.push(Pair(edgeWeight, adjNode));
                }
            }
        }
        return sum;
    }
};

int main()
{
    int V = 5;
    vector<vector<vector<int>>> adj(V);

    int edges[][3] = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};

    for (int i = 0; i < 6; ++i)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int sum = Prim::spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << sum << endl;

    return 0;
}
