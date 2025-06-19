#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSumNonAdjacent(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    int inc = nums[0];
    int exc = 0;

    for (int i = 1; i < n; i++) {
        int ninc = exc + nums[i];
        int nexc = max(inc, exc);

        inc = ninc;
        exc = nexc;
    }

    return max(inc, exc);
}

int main() {
    vector<int> arr = {5, 10, 10, 100, 5, 6};
    int result = maxSumNonAdjacent(arr);
    cout << "Maximum sum of non-adjacent elements: " << result << endl;
    return 0;
}
