#include <iostream>
#include <vector>

using namespace std;

bool checkBit(int n, int i) {
    return ((n & (1 << i)) != 0);
}

int findMaxAndPair(vector<int>& arr) {
    int n = arr.size();

    for (int i = 31; i >= 0; i--) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (checkBit(arr[j], i)) {
                c++;
            }
        }

        if (c >= 2) {
            for (int j = 0; j < n; j++) {
                if (!checkBit(arr[j], i)) {
                    arr[j] = 0;
                }
            }
        }
    }

    int idx1 = -1;
    int idx2 = -1;

    for (int k = 0; k < n; k++) {
        if (arr[k] > 0 && idx1 == -1) {
            idx1 = k;
        } else if (arr[k] > 0 && idx1 != -1) {
            idx2 = k;
            break;
        }
    }

    int ans = (arr[idx1] & arr[idx2]);
    return ans;
}

int main() {
    vector<int> arr = {2, 4, 5, 7, 9};

    int result = findMaxAndPair(arr);
    cout << "Maximum AND pair: " << result << endl; // Expected output: 0

    return 0;
}
