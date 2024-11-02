#include <bits/stdc++.h>

using namespace std;

bool isRainbowArray(vector<int>& arr) {
    int n = arr.size();

    // Check if the array starts and ends with 1
    if (arr[0] != 1 || arr[n - 1] != 1) return false;

    int left = 0, right = n - 1;
    int currentNumber = 1;

    while (left <= right) {
        if (arr[left] != arr[right] || arr[left] != currentNumber) {
            return false;
        }

        // Move left pointer forward if it matches currentNumber
        while (left <= right && arr[left] == currentNumber) {
            left++;
        }

        // Move right pointer backward if it matches currentNumber
        while (left <= right && arr[right] == currentNumber) {
            right--;
        }

        // Move to the next number
        currentNumber++;

        // Stop if we reach beyond 7 since there's no number beyond 7 in a rainbow array
        if (currentNumber > 7) {
            break;
        }
    }

    // Finally, check if we have processed all numbers from 1 to 7 correctly
    return currentNumber == 8 && left > right; // Ensure currentNumber reached 8 after processing 1-7
}

int main() {
    vector<vector<int>> test_cases = {
        {19, 1, 2, 3, 4, 4, 5, 6, 6, 6, 7, 6, 6, 6, 5, 4, 4, 3, 2, 1},
        {14, 1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1, 1},
        {13, 1, 2, 3, 4, 5, 6, 8, 6, 5, 4, 3, 2, 1}
    };

    for (const auto& test_case : test_cases) {
        vector<int> arr(test_case.begin() + 1, test_case.end());

        if (isRainbowArray(arr)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
