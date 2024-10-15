#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector < vector < int >> tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    deque < int > q;
    vector < bool > visited(n+1, false);
    q.push_back(1);
    visited[1] = true;

    while (!q.empty()) {
        int rem = q.front();
        q.pop_front();

        cout << rem << " ";

        for (int i: tree[rem]) {
            if (visited[i] == false) {
                visited[i] = true;
                q.push_back(i);
            }
        }
    }
    cout << endl;

}

/*
10
1 2
1 3
1 4
2 5
5 9
3 6
3 7
6 10
4 8

*/