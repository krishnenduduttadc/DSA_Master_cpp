#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class AccountsMerge {
private:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

public:
    AccountsMerge(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        int ulp = findUPar(parent[node]);
        parent[node] = ulp;
        return parent[node];
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n = details.size();
        AccountsMerge ds(n);
        unordered_map<string, int> mapMailNode;

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < details[i].size(); ++j) {
                string mail = details[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<vector<string>> mergedMail(n);
        for (auto& it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; ++i) {
            if (mergedMail[i].empty()) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            temp.insert(temp.end(), mergedMail[i].begin(), mergedMail[i].end());
            ans.push_back(temp);
        }
        return ans;
    }
};

int main() {
    vector<vector<string>> accounts = {
        {"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}
    };

    AccountsMerge obj(accounts.size());
    vector<vector<string>> ans = obj.accountsMerge(accounts);

    for (const auto& vec : ans) {
        cout << vec[0] << ": ";
        for (int i = 1; i < vec.size(); ++i) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
