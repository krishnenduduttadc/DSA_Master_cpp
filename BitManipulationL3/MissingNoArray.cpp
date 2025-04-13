#include <iostream>
using namespace std;

int findMissingNumber(int nums[], int n) {
    int missing = 0;
    for (int i = 0; i <= n; i++) {
        missing ^= i ^ nums[i];
    }
    return missing;
}

int main() {
    int nums[] = {0, 1, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]) - 1; // n is the length of the array minus 1
    int missing = findMissingNumber(nums, n);
    
    cout << "Missing number: " << missing << endl; // Output: 2

    return 0;
}
