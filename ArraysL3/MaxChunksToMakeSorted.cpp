#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class MaxChunksToMakeSorted {
public:
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
};

int main() {
    MaxChunksToMakeSorted solution;
    vector<int> arr1 = {4, 3, 2, 1, 0};
    int result1 = solution.maxChunksToSorted(arr1);
    cout << "Max chunks to sort: " << result1 << endl; // Expected output: 1
    return 0;
}
