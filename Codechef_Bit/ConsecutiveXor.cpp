#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T = 3;
    vector<vector<int>> test_cases = {
        {3, 2, 2, 3},
        {0, 1, 2, 3, 4, 5},
        {1, 2, 4}
    };

    for (int t = 0; t < T; ++t) {
        int N = test_cases[t].size();
        vector<int> A = test_cases[t];
        int xorsum = 0;

        for (int i = 0; i < N; ++i) {
            xorsum ^= A[i];
        }

        if (N % 2 == 1 || xorsum == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
