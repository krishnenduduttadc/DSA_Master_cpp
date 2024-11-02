#include <bits/stdc++.h>
using namespace std;

bool isSub(string s1, string s2) {
    int j = 0;
    for (int i = 0; i < s2.length() && j < s1.length(); i++) {
        if (s1[j] == s2[i]) {
            j++;
        }
    }
    return (j == s1.length());
}

int main() {
    vector<pair<string, string>> test_cases = {
        {"john", "johanna"},
        {"ira", "ira"},
        {"kayla", "jayla"}
    };

    for (int i = 0; i < test_cases.size(); i++) {
        string M = test_cases[i].first;
        string W = test_cases[i].second;

        if (isSub(M, W) || isSub(W, M)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
