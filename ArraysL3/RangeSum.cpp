#include <iostream>
#include <vector>
using namespace std;

class RangeSum {
private:
    static vector<int> psum;

public:
    static void NumArray(vector<int>& nums) {
        psum.resize(nums.size());
        psum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            psum[i] = psum[i - 1] + nums[i];
        }
    }

    static int sumRange(int i, int j) {
        if (i == 0) {
            return psum[j];
        }
        return psum[j] - psum[i - 1];
    }
};

vector<int> RangeSum::psum; // Definition of static member variable

int main() {
    vector<int> arr = {1, 2, 3, 4};
    RangeSum::NumArray(arr);
    int res = RangeSum::sumRange(1, 2);
    cout << res << endl; // Output should be 5

    return 0;
}
