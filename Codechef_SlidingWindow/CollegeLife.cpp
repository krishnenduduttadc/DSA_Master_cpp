#include <bits/stdc++.h>
using namespace std;

int main() {
    int T = 3; // Number of test cases
    vector<pair<vector<int>, vector<int>>> testCases = {
        {{1, 3}, {2, 4}},
        {{100, 200, 300}, {1}},
        {{1, 2}, {1}},
        {{100, 200}, {}}
    };

    for (int t = 0; t < T; ++t) {
        vector<int> F = testCases[t].first;
        vector<int> C = testCases[t].second;

        int switches = 0;
        int i = 0, j = 0;
        bool watchingFootball = true;  // Start by watching football

        while (i < F.size() && j < C.size()) {
            if (watchingFootball) {
                if (F[i] < C[j]) {
                    ++i; // Continue watching football
                } else {
                    watchingFootball = false; // Switch to cricket
                    ++switches;
                }
            } else {
                if (C[j] < F[i]) {
                    ++j; // Continue watching cricket
                } else {
                    watchingFootball = true; // Switch to football
                    ++switches;
                }
            }
        }

        // After finishing one of the lists, switch to the other list if there are remaining events
        if (i < F.size() || j < C.size()) {
            ++switches;
        }

        cout << switches << endl;
    }
    
    return 0;
}
