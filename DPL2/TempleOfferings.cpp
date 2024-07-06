#include <iostream>
#include <vector>
using namespace std;

int totalOfferings(vector<int>& height) {
    int n = height.size();
    vector<int> larr(n, 0); // Left offerings array
    vector<int> rarr(n, 0); // Right offerings array

    // Calculate left offerings
    larr[0] = 1;
    for (int i = 1; i < n; i++) {
        if (height[i] > height[i - 1]) {
            larr[i] = larr[i - 1] + 1;
        } else {
            larr[i] = 1;
        }
    }

    // Calculate right offerings
    rarr[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (height[i] > height[i + 1]) {
            rarr[i] = rarr[i + 1] + 1;
        } else {
            rarr[i] = 1;
        }
    }

    // Calculate total offerings
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max(larr[i], rarr[i]);
    }
    return ans;
}

int main() {
    vector<int> height = {2, 3, 5, 6, 4, 8, 9};
    cout << totalOfferings(height) << endl;
    return 0;
}
