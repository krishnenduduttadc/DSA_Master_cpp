#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GoodIntegers(vector<int>& arr) {
    sort(arr.begin(), arr.end()); // Sort the array

    int ans = 0;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == i) { // Check if the value at index i matches i
            ++ans;
        }
    }

    return ans; // Return the count of good integers
}

int main() {
    vector<int> arr = {0, 1, 5, 7, 8, 9, 4};

    cout << GoodIntegers(arr) << endl;

    return 0;
}
