#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int ZeroSumSubarray(vector<int>& arr) {
    unordered_set<int> us;
    int prefix_sum = 0;
    us.insert(0); // Insert 0 initially to handle cases where the prefix_sum itself is zero
    for (int i = 0; i < arr.size(); ++i) {
        prefix_sum += arr[i];
        if (us.count(prefix_sum) > 0)
            return 1; // Found a subarray with sum zero
        us.insert(prefix_sum);
    }
    return 0; // No subarray with sum zero found
}

int main() {
    vector<int> arr = {5, 3, 9, -4, -6, 7, -1};
    cout << ZeroSumSubarray(arr) << endl;
    return 0;
}
