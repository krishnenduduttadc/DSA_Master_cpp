#include <iostream>
#include <vector>

using namespace std;

int findElement(vector<int>& arr) {
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main() {
    vector<int> arr = {2, 4, 1, 2, 4};

    int result = findElement(arr);
    cout << "Element occurring exactly four times: " << result << endl; // Expected output: 1

    return 0;
}
