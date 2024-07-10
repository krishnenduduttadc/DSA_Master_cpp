#include <iostream>
#include <vector>
#include <stack>
#include <limits>
using namespace std;

class ShortestPathInDAG
{
public:
    struct Pair
    {
        int first, second;
        Pair(int _first, int _second)
        {
            first = _first;
            second = _second;
        }
    };

    void topologicalSort(int node, vector<vector<Pair>> &adj, vector<int> &visited, stack<int> &st)
    {
        visited[node] = 1;
        for (Pair neighbor : adj[node])
        {
            int v = neighbor.first;
            if (visited[v] == 0)
            {
                topologicalSort(v, adj, visited, st);
            }
        }
        st.push(node);
    }

    vector<int> findShortestPaths(int numNodes, int numEdges, vector<vector<int>> &edges)
    {
        vector<vector<Pair>> adjacencyList(numNodes);

        // Constructing adjacency list
        for (int i = 0; i < numEdges; ++i)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adjacencyList[u].push_back(Pair(v, weight));
        }

        vector<int> visited(numNodes, 0);
        stack<int> st;

        // Perform topological sorting
        for (int i = 0; i < numNodes; ++i)
        {
            if (visited[i] == 0)
            {
                topologicalSort(i, adjacencyList, visited, st);
            }
        }

        vector<int> distances(numNodes, numeric_limits<int>::max());
        distances[0] = 0; // Distance to source node is 0

        // Process vertices in topological order
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            // Update distances of all adjacent vertices
            for (Pair neighbor : adjacencyList[node])
            {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (distances[node] != numeric_limits<int>::max() && distances[node] + weight < distances[v])
                {
                    distances[v] = distances[node] + weight;
                }
            }
        }

        // Handling nodes that are not reachable
        for (int i = 0; i < numNodes; ++i)
        {
            if (distances[i] == numeric_limits<int>::max())
            {
                distances[i] = -1;
            }
        }

        return distances;
    }
};

int main()
{
    int numNodes = 6, numEdges = 7;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};

    ShortestPathInDAG shortestPathFinder;
    vector<int> result = shortestPathFinder.findShortestPaths(numNodes, numEdges, edges);

    for (int distance : result)
    {
        cout << distance << " ";
    }
    cout << endl;

    return 0;
}
