#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int cur, stack<int>& st) {
    visited[cur] = true;
    for (int nbr : graph[cur]) {
        if (!visited[nbr]) {
            dfs(graph, visited, nbr, st);
        }
    }
    st.push(cur);
}

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int cur) {
    visited[cur] = true;
    for (int nbr : graph[cur]) {
        if (!visited[nbr]) {
            dfs(graph, visited, nbr);
        }
    }
}

int findMotherVertex(int N, vector<vector<int>>& adj) {
    vector<bool> visited(N, false);
    stack<int> st;

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs(adj, visited, i, st);
        }
    }

    int candidate = st.top();
    visited.assign(N, false);
    int count = 0;

    dfs(adj, visited, candidate);

    if (count == N) {
        return candidate + 1; // +1 because problem statement uses 1-based indexing
    } else {
        return -1;
    }
}

int main() {
    int n = 4;
    vector<vector<int>> graph(n);

    // Hardcoded input
    graph[0].push_back(1);
    graph[1].push_back(2);
    graph[2].push_back(3);

    int m = graph.size();
    cout << findMotherVertex(n, graph) << endl;

    return 0;
}
