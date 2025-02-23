#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For INT_MIN and INT_MAX

using namespace std;

double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    
    // Ensure that 'a' is the smaller array for binary search optimization
    if (n1 > n2) 
        return findMedianSortedArrays(b, a);

    int lo = 0, hi = n1, total = n1 + n2;

    while (lo <= hi) {
        int m1 = (lo + hi) / 2;
        int m2 = (total + 1) / 2 - m1;

        int am1 = (m1 == 0) ? INT_MIN : a[m1 - 1];
        int am = (m1 == n1) ? INT_MAX : a[m1];
        int bm1 = (m2 == 0) ? INT_MIN : b[m2 - 1];
        int bm = (m2 == n2) ? INT_MAX : b[m2];

        if (am1 <= bm && bm1 <= am) {
            if (total % 2 != 0) 
                return max(am1, bm1);
            return (max(am1, bm1) + min(am, bm)) / 2.0;
        } else if (am1 > bm) {
            hi = m1 - 1;
        } else {
            lo = m1 + 1;
        }
    }

    return 0.0; // Should never reach here
}

int main() {
    vector<int> a1 = {1, 3};
    vector<int> b1 = {2};
    cout << "Median of arrays a1 and b1: " << findMedianSortedArrays(a1, b1) << endl; // Output: 2.0

    vector<int> a2 = {1, 2};
    vector<int> b2 = {3, 4};
    cout << "Median of arrays a2 and b2: " << findMedianSortedArrays(a2, b2) << endl; // Output: 2.5

    return 0;
}
