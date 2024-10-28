#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5, d = 2; // Hardcoded number of elements and the threshold
    int a[100010] = {0, 1, 3, 3, 9, 4}; // Hardcoded input array

    // Sort the array
    sort(a + 1, a + 1 + n);

    int pos = 1;
    int res = 0;

    // Pairing logic
    while (pos < n) {
        if (abs(a[pos] - a[pos + 1]) <= d) {
            res++;        // Found a valid pair
            pos += 2;     // Move past the paired elements
        } else {
            pos++;        // Move to the next element
        }
    }

    cout << res << endl; // Output the result

    return 0;
}

/*
Expected Output:
2
*/
