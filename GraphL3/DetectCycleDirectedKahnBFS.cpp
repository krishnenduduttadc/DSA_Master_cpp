#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class DetectCycleDirectedKahnBFS {
public:
    bool isCyclic(int N, vector<vector<int>>& adj) {
        vector<int> indegree(N, 0);
        for (int i = 0; i < N; i++) {
            for (int it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for (int it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return cnt != N;
    }
};

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[4].push_back(2);

    DetectCycleDirectedKahnBFS obj;
    bool ans = obj.isCyclic(V, adj);
    if (ans)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
