#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> F(N), C(M);
        
        for (int i = 0; i < N; ++i) {
            cin >> F[i];
        }
        for (int i = 0; i < M; ++i) {
            cin >> C[i];
        }

        int switches = 0;
        int i = 0, j = 0;
        bool watchingFootball = true;  // Start by watching football

        while (i < N && j < M) {
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
        if (i < N || j < M) {
            ++switches;
        }

        cout << switches << endl;
    }
    return 0;

}


/*
3
2 2
1 3
2 4
3 1
100 200 300
1
1 2
1
100 200

*/