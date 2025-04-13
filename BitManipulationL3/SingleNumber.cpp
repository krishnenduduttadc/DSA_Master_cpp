#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}

int main() {
    vector<int> arr = {2, 2, 3, 3, 4, 6, 6};
    cout << singleNumber(arr) << endl; // Output: 4

    return 0;
}
