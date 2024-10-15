#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // This is our adjacency matrix
    // All the elements are initialized to zero
    vector < vector < int >> adjMatrix(n, vector < int > (n, 0));

    // Take the input for all the edges
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;

        // Adding an edge from u to v
        adjMatrix[u][v] = 1;
    }

    // Printing the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}


/*
6
0 1
0 2
1 3
1 4
2 5

*/