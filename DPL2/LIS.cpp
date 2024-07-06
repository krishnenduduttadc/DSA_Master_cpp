#include <iostream>
#include <vector>
using namespace std;

void LIS(int arr[], int n) {
    vector<int> dp(n, 1); // dp[i] will store the length of LIS ending at index i
    int omax = 1; // To store the overall maximum length of LIS

    for (int i = 1; i < n; i++) {
        int max_len = 0;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                if (dp[j] > max_len) {
                    max_len = dp[j];
                }
            }
        }
        dp[i] = max_len + 1;
        if (dp[i] > omax) {
            omax = dp[i];
        }
    }

    cout << omax << " "; // Print the length of the LIS

    // Printing the LIS itself (optional)
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    LIS(arr, n);

    return 0;
}