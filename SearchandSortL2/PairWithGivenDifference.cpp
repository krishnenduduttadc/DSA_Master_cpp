#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void findPair(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());

    int i = 0;
    int j = 1;
    while (i < arr.size() && j < arr.size()) {
        if (arr[j] - arr[i] == target) {
            cout << arr[i] << " " << arr[j] << endl;
            return;
        } else if (arr[j] - arr[i] < target) {
            j++;
        } else {
            i++;
        }
    }
    cout << "-1" << endl;
}

int main() {
    // Hardcoded input
    vector<int> arr = {1, 7, 3, 10, 5, 6};
    int target = 4;

    // Call the findPair function to find the pair with given difference
    findPair(arr, target);

    return 0;
}
