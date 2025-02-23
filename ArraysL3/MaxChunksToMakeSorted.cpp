#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int maxTillNow = INT_MIN;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        maxTillNow = max(maxTillNow, arr[i]);
        if (i == maxTillNow) {
            ans++;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 3, 2, 1, 0};
    int result = maxChunksToSorted(arr);
    cout << "Max chunks to sort: " << result << endl; // Expected output: 1
    return 0;
}
