#include <iostream>
#include <vector>
using namespace std;

class NumberofSubArrayswithGCDequaltoK {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        for (int sp = 0; sp < n; sp++) {
            int ans = 0;
            for (int ep = sp; ep < n; ep++) {
                ans = gcd(ans, nums[ep]);

                if (ans < k) {
                    break;
                }
                if (ans == k) {
                    count++;
                }
            }
        }

        return count;
    }

    int gcd(int a, int b) {
        if (a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }
};

int main() {
    NumberofSubArrayswithGCDequaltoK solution;

    // Hard-coded input
    vector<int> nums = {2, 4, 6, 8, 3, 9};
    int k = 3;

    int result = solution.subarrayGCD(nums, k);
    cout << "Number of subarrays with GCD equal to " << k << ": " << result << endl;

    return 0;
}
