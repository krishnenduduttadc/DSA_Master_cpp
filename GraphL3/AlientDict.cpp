#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class AlienDictionary {
private:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; ++i) {
            for (int it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo;
    }

public:
    string findOrder(vector<string>& dict, int N, int K) {
        vector<vector<int>> adj(K);

        for (int i = 0; i < N - 1; ++i) {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.length(), s2.length());
            for (int ptr = 0; ptr < len; ++ptr) {
                if (s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(K, adj);
        string ans = "";
        for (int it : topo) {
            ans += (char)(it + 'a');
        }

        return ans;
    }
};

int main() {
    int N = 5, K = 4;
    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};

    AlienDictionary obj;
    string ans = obj.findOrder(dict, N, K);

    cout << "Topological Order: " << ans << endl;

    return 0;
}
