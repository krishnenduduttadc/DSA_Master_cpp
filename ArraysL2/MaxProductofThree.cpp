#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProduct(vector<int>& nums) {
    int min1 = INT_MAX, min2 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

    for (int val : nums) {
        if (val > max1) {
            max3 = max2;
            max2 = max1;
            max1 = val;
        } else if (val > max2) {
            max3 = max2;
            max2 = val;
        } else if (val > max3) {
            max3 = val;
        }

        if (val < min1) {
            min2 = min1;
            min1 = val;
        } else if (val < min2) {
            min2 = val;
        }
    }

    return max(min1 * min2 * max1, max1 * max2 * max3);
}

int main() {
    vector<int> nums = {2, 4, 6, 7};
    int result = maxProduct(nums);
    cout << result << endl;
    return 0;
}
