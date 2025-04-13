#include <iostream>
using namespace std;

int countBits(int a, int b) {
    int count = 0;
    int diff = a ^ b; // XOR to find differing bits

    // Count the number of set bits in the XOR result
    while (diff) {
        count += diff & 1;
        diff >>= 1;
    }

    return count;
}

int sumOfBitDifferences(int arr[], int n) {
    int sum = 0;

    // Compare every pair of numbers in the array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += countBits(arr[i], arr[j]);
        }
    }

    return sum;
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = sumOfBitDifferences(arr, n);
    cout << result << endl;

    return 0;
}
