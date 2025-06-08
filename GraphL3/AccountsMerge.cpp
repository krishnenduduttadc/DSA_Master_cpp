#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Data Structures
vector<int> rankDSU, parent, sizeDSU;

void initDisjointSet(int n) {
    rankDSU.resize(n + 1, 0);
    parent.resize(n + 1);
    sizeDSU.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        sizeDSU[i] = 1;
    }
}

int findUPar(int node) {
    if (node == parent[node])
        return node;
    return parent[node] = findUPar(parent[node]);
}

void unionBySize(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v) return;
    if (sizeDSU[ulp_u] < sizeDSU[ulp_v]) {
        parent[ulp_u] = ulp_v;
        sizeDSU[ulp_v] += sizeDSU[ulp_u];
    } else {
        parent[ulp_v] = ulp_u;
        sizeDSU[ulp_u] += sizeDSU[ulp_v];
    }
}

// Main logic for merging accounts
vector<vector<string>> accountsMerge(vector<vector<string>> &details) {
    int n = details.size();
    initDisjointSet(n);
    sort(details.begin(), details.end());
    unordered_map<string, int> mapMailNode;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < details[i].size(); j++) {
            string mail = details[i][j];
            if (mapMailNode.find(mail) == mapMailNode.end()) {
                mapMailNode[mail] = i;
            } else {
                unionBySize(i, mapMailNode[mail]);
            }
        }
    }

    vector<string> mergedMail[n];
    for (auto it : mapMailNode) {
        string mail = it.first;
        int node = findUPar(it.second);
        mergedMail[node].push_back(mail);
    }

    vector<vector<string>> ans;
    for (int i = 0; i < n; i++) {
        if (mergedMail[i].size() == 0) continue;
        sort(mergedMail[i].begin(), mergedMail[i].end());
        vector<string> temp;
        temp.push_back(details[i][0]);
        for (auto it : mergedMail[i]) {
            temp.push_back(it);
        }
        ans.push_back(temp);
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<vector<string>> accounts = {
        {"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}
    };

    vector<vector<string>> ans = accountsMerge(accounts);
    for (auto acc : ans) {
        cout << acc[0] << ":";
        int size = acc.size();
        for (int i = 1; i < size; i++) {
            cout << acc[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
