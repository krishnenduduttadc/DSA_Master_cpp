#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class FlipBits {
public:
    static int maxOnes(vector<int>& a, int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                a[i] = 1;
            } else {
                a[i] = -1;
                count++;
            }
        }

        int csum = 0;
        int osum = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (csum >= 0) {
                csum += a[i];
            } else {
                csum = a[i];
            }

            osum = max(csum, osum);
        }

        if (osum > 0) {
            return osum + count;
        } else {
            return count;
        }
    }
};

int main() {
    // Test case 1
    vector<int> arr1 = {1, 0, 1, 1, 0, 1};
    int result1 = FlipBits::maxOnes(arr1, arr1.size());
    cout << "Max ones after modification: " << result1 << endl; // Expected output: 6
    return 0;
}
