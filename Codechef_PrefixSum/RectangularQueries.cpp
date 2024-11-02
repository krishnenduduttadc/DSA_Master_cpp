#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 300;
const int MAX_VAL = 10;

int main() {
    int N = 3; // Hardcoded size of the grid
    vector<vector<int>> A = {
        {1, 2, 3},
        {3, 2, 1},
        {5, 6, 3}
    };

    // Create prefix sums for each distinct number (1 to 10)
    vector<vector<vector<int>>> prefix(MAX_VAL + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, 0)));

    for (int d = 1; d <= MAX_VAL; ++d) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                int isPresent = (A[i-1][j-1] == d) ? 1 : 0;
                prefix[d][i][j] = prefix[d][i-1][j] + prefix[d][i][j-1] - prefix[d][i-1][j-1] + isPresent;
            }
        }
    }

    // Hardcoded number of queries
    int Q = 3; 
    vector<vector<int>> queries = {
        {1, 1, 2, 3},
        {2, 2, 2, 2},
        {1, 1, 3, 3}
    };
    
    for (int k = 0; k < Q; ++k) {
        int x1 = queries[k][0], y1 = queries[k][1], x2 = queries[k][2], y2 = queries[k][3];

        int distinctCount = 0;
        for (int d = 1; d <= MAX_VAL; ++d) {
            int countD = prefix[d][x2][y2] - prefix[d][x1-1][y2] - prefix[d][x2][y1-1] + prefix[d][x1-1][y1-1];
            if (countD > 0) {
                ++distinctCount;
            }
        }
        cout << distinctCount << endl; // Output the count of distinct numbers in the range
    }

    return 0;
}
