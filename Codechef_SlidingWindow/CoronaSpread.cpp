#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<int>> test_cases = {
        {2, 3, 6},
        {3, 1, 3, 5},
        {5, 1, 2, 5, 6, 7}
    };

    for (auto &test_case : test_cases) {
        int N = test_case[0]; // Number of people
        vector<int> arr(test_case.begin() + 1, test_case.end()); // Positions of the people

        int minInfected = N; // Initialize to maximum possible value
        int maxInfected = 1; // Initialize to minimum possible value
        int count = 1; // Start counting from the first person

        for (int i = 1; i < N; i++) {
            if (arr[i] - arr[i - 1] <= 2) {
                count++;
            } else {
                minInfected = min(minInfected, count);
                maxInfected = max(maxInfected, count);
                count = 1;
            }
        }

        minInfected = min(minInfected, count);
        maxInfected = max(maxInfected, count);

        // Output the result
        cout << minInfected << " " << maxInfected << endl;
    }

    return 0;
}
