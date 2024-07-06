#include <iostream>
#include <unordered_map>
using namespace std;

int sol(int arr[], int n) {
    int ans = 0;
    unordered_map<int, int> map;
    map[0] = -1;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            sum += -1;
        } else if (arr[i] == 1) {
            sum += +1;
        }

        if (map.find(sum) != map.end()) {
            int idx = map[sum];
            int len = i - idx;
            if (len > ans) {
                ans = len;
            }
        } else {
            map[sum] = i;
        }
    }
    return ans;
}

int main() {
    int arr[] = {0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << sol(arr, n) << endl; // Output: 10

    return 0;
}
