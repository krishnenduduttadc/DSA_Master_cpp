#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;


    static int find(vector<int> arr, int n, int m) {
        sort(arr.begin(), arr.end());

        int minDifference = INT_MAX;

        for (int i = 0; i <= n - m; ++i) {
            int minWeight = arr[i];
            int maxWeight = arr[i + m - 1];
            int difference = maxWeight - minWeight;
            
            if (difference < minDifference) {
                minDifference = difference;
            }
        }

        return minDifference;
    }


int main() {
    int n = 8;
    vector<int> arr = {3, 4, 1, 9, 56, 7, 9, 12};
    int m = 5;

    int ans = find(arr, n, m);

    cout << ans << endl;

    return 0;
}
