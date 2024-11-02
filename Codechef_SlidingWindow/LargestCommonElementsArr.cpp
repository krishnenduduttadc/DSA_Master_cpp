#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestCommonElement(vector<int>& arr1, vector<int>& arr2) {
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int i = arr1.size() - 1, j = arr2.size() - 1;

    while (i >= 0 && j >= 0) {
        if (arr1[i] == arr2[j]) {
            return arr1[i];
        } else if (arr1[i] > arr2[j]) {
            i--;
        } else {
            j--;
        }
    }
    return -1;
}

int main() {
    vector<int> arr1 = {1, 3, 4, 6, 7}; // Hardcoded array 1
    vector<int> arr2 = {2, 3, 5, 6, 7, 8}; // Hardcoded array 2

    cout << largestCommonElement(arr1, arr2) << endl;

    return 0;
}
