#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int orderOfRemoval(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end()); // Sort the array in ascending order

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int temp = arr[i] * (n - i);
        ans += temp;
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int result = orderOfRemoval(arr);
    cout << "Order of removal: " << result << endl;

    return 0;
}
