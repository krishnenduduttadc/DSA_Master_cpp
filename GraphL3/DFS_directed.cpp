#include <iostream>
#include <vector>

using namespace std;

static void dfs(int s, vector<bool> vis, vector<vector<int>> adj, vector<int> &ls)
{
    vis[s] = true;
    ls.push_back(s);
    for (int it : adj[s])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, ls);
        }
    }
}

int main()
{
    int V = 5;
    vector<bool> vis(V + 1, false);
    vector<vector<int>> adj(V + 1);

    adj[1].push_back(3);
    adj[1].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(5);

    vector<vector<int>> res;
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            vector<int> ls;
            dfs(i, vis, adj, ls);
            res.push_back(ls);
        }
    }

    for (vector<int> component : res)
    {
        for (int node : component)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
