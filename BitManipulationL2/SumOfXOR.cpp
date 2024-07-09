#include <iostream>
#include <vector>

using namespace std;

class SumOfXOR {
public:
    long sumXOR(int arr[], int n) {
        long ans = 0;

        for (int i = 31; i >= 0; i--) {
            long ZeroCnt = 0;
            long OneCnt = 0;
            for (int j = 0; j < n; j++) {
                if ((arr[j] & (1 << i)) != 0) {
                    OneCnt += 1;
                } else {
                    ZeroCnt += 1;
                }
            }

            ans += (1LL << i) * (OneCnt * ZeroCnt);
        }

        return ans;
    }
};

int main() {
    SumOfXOR solution;

    // Test case
    int arr1[] = {1, 3, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    long result1 = solution.sumXOR(arr1, n1);
    cout << "Sum of XOR for arr1: " << result1 << endl; // Expected output: 12

    return 0;
}
