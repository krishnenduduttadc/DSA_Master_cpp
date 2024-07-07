#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to solve the problem
vector<int> solve(vector<int>& arr) {
    unordered_map<int, int> freqMap;

    // Count frequencies of each stick length
    for (int ele : arr) {
        freqMap[ele]++;
    }

    int maxArea = 0;
    int maxSquares = 0;

    // Iterate over the frequencies to find the maximum square area
    for (auto& entry : freqMap) {
        int length = entry.first;
        int frequency = entry.second;

        if (frequency >= 4) {
            int area = length * length;
            if (area > maxArea) {
                maxArea = area;
                maxSquares = frequency / 4;
            }
        }
    }

    // Prepare the result as per the problem statement
    vector<int> result;
    if (maxArea == 0) {
        result.push_back(-1);
    } else {
        result.push_back(maxArea);
        result.push_back(maxSquares);
    }

    return result;
}

// Utility function to test and print the result
void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Hardcoded input
    vector<int> arr = {2, 3, 2, 3, 2, 3, 3, 3, 2, 3, 3, 3, 4};

    // Call the solve function to find the result
    vector<int> ans = solve(arr);

    // Print the result
    printResult(ans);

    return 0;
}
