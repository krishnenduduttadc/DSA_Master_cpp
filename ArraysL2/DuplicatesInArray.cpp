#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> dups(vector<int>& nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        int idx = abs(nums[i]) - 1;
        int val = nums[idx];
        if (val < 0) {
            res.push_back(idx + 1);
        } else {
            nums[idx] *= -1;
        }
    }
    return res;
}

int main() {
    vector<int> dupli = {1, 1, 2, 2, 3, 4, 4};
    vector<int> dup = dups(dupli);

    for (int i = 0; i < dup.size(); i++) {
        cout << dup[i] << endl;
    }

    return 0;
}
