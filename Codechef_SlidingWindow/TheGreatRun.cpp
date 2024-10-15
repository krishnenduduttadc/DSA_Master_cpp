#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T, N, K;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        vector<int> girls(N);
        int currentImpressed = 0, maxImpressed = 0;
        for (int i = 0; i < N; i++) {
            cin >> girls[i];
            if (i < K) currentImpressed += girls[i];
        }
        maxImpressed = currentImpressed;
        for (int i = K; i < N; i++) {
            currentImpressed = currentImpressed - girls[i - K] + girls[i];
            maxImpressed = max(maxImpressed, currentImpressed);
        }
        cout << maxImpressed << endl;
    }
    return 0;
}

/*
1
7 2
2 4 8 1 2 1 8

*/