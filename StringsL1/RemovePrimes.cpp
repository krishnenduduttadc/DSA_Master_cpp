#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int val) {
    if (val <= 1) return false; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= val; i++) {
        if (val % i == 0) {
            return false;
        }
    }
    return true;
}

void solution(vector<int>& nums) {
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (isPrime(nums[i])) {
            nums.erase(nums.begin() + i); // Remove prime number
        }
    }
}

int main() {
    vector<int> nums = {3, 12, 13, 15};

    solution(nums);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
