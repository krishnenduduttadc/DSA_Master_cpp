#include <bits/stdc++.h>

using namespace std;
void dfs(int s,
    const vector < vector < int >> & adjList, vector < bool > & visited, int & leafCount) {
    visited[s] = true;
    bool isLeaf = true;
    for (int it: adjList[s]) {
        if (visited[it] == false) {
            isLeaf = false;
            dfs(it, adjList, visited, leafCount);
        }
    }

    if (isLeaf == true) {
        leafCount++;
    }

}

int main() {
    int N;
    cin >> N; // Read number of nodes

    vector < vector < int >> adjList(N); // Create an adjacency list for the tree

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b; // Read each edge
        // Assuming it's an undirected tree, add both connections
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    vector < bool > visited(N, false);
    int leafCount = 0;
    dfs(0, adjList, visited, leafCount);
    cout  << leafCount << endl;


}

/*
8
0 1
0 2
1 3
1 4
2 5
3 6
5 7
*/