#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; // Number of test cases
    cin >> T;

    while (T--) {
        int N; // Number of people
        cin >> N;

        vector < int > arr(N); // Array to store the positions of the people
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }

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

}


/*
3
2
3 6
3
1 3 5
5
1 2 5 6 7

*/