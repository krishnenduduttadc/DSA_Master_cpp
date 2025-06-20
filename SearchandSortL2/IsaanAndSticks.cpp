#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solve(vector<int>& arr) {
    unordered_map<int, int> freqMap;

    for (int ele : arr) {
        freqMap[ele]++;
    }

    int maxArea = 0;
    int maxSquares = 0;

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

    vector<int> result;
    if (maxArea == 0) {
        result.push_back(-1);
    } else {
        result.push_back(maxArea);
        result.push_back(maxSquares);
    }

    return result;
}

void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {2, 3, 2, 3, 2, 3, 3, 3, 2, 3, 3, 3, 4};

    vector<int> ans = solve(arr);

    printResult(ans);

    return 0;
}
