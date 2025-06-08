#include <bits/stdc++.h>
using namespace std;

// Function to check whether a component is bipartite using BFS
bool check(int start, int V, vector<int> adj[], int color[])
{
	queue<int> q;
	q.push(start);
	color[start] = 0;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (auto it : adj[node])
		{
			// If neighbor hasn't been colored
			if (color[it] == -1)
			{
				color[it] = !color[node]; // Assign opposite color
				q.push(it);
			}
			// If neighbor has same color → Not bipartite
			else if (color[it] == color[node])
			{
				return false;
			}
		}
	}
	return true;
}

// Main function to check bipartiteness of graph
bool isBipartite(int V, vector<int> adj[])
{
	int color[V];
	fill(color, color + V, -1); // Initially uncolored

	for (int i = 0; i < V; i++)
	{
		if (color[i] == -1)
		{
			if (!check(i, V, adj, color))
			{
				return false;
			}
		}
	}
	return true;
}

// Utility to add undirected edge
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{
	vector<int> adj[4];

	addEdge(adj, 0, 2);
	addEdge(adj, 0, 3);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 1);

	bool ans = isBipartite(4, adj);

	if (ans)
	{
		cout << "Bipartite" << endl;
	}
	else
	{
		cout << "Not Bipartite" << endl;
	}
	return 0;
}
