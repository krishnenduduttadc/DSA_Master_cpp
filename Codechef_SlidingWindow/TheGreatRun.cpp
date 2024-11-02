#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<tuple<int, int, vector<int>>> test_cases = {
        {7, 2, {2, 4, 8, 1, 2, 1, 8}}
    };

    for (const auto& [N, K, girls] : test_cases) {
        int currentImpressed = 0, maxImpressed = 0;

        for (int i = 0; i < N; i++) {
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
