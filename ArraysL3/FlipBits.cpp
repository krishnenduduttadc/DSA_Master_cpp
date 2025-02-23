#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxOnes(vector<int>& a, int n) {
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

    return osum > 0 ? osum + count : count;
}

int main() {
    vector<int> arr = {1, 0, 1, 1, 0, 1};
    int result = maxOnes(arr, arr.size());
    cout << "Max ones after modification: " << result << endl;
    return 0;
}
