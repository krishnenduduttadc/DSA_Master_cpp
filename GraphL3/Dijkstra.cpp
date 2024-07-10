#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Dijkstra
{
public:
    struct Pair
    {
        int node;
        int distance;

        Pair(int _distance, int _node)
        {
            distance = _distance;
            node = _node;
        }
    };

    struct compare
    {
        bool operator()(Pair const &p1, Pair const &p2)
        {
            return p1.distance > p2.distance;
        }
    };

    vector<int> dijkstra(int V, vector<vector<vector<int>>> &adj, int s)
    {
        priority_queue<Pair, vector<Pair>, compare> pq;
        vector<int> dist(V, INT_MAX);
        dist[s] = 0;
        pq.push(Pair(0, s));

        while (!pq.empty())
        {
            int dis = pq.top().distance;
            int node = pq.top().node;
            pq.pop();

            for (int i = 0; i < adj[node].size(); i++)
            {
                int adjNode = adj[node][i][0];
                int edgeWeight = adj[node][i][1];

                if (dis + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push(Pair(dist[adjNode], adjNode));
                }
            }
        }
        return dist;
    }
};

int main()
{
    int V = 3, E = 3, S = 2;

    vector<vector<vector<int>>> adj(V);

    adj[0].push_back({1, 1});
    adj[0].push_back({2, 6});

    adj[1].push_back({2, 3});
    adj[1].push_back({0, 1});

    adj[2].push_back({1, 3});
    adj[2].push_back({0, 6});

    Dijkstra dijkstraSolver;
    vector<int> res = dijkstraSolver.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
