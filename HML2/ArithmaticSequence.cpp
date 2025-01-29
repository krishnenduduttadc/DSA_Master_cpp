#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>

using namespace std;

bool isArithmeticSequence(const vector<int> arr) {
    if (arr.size() <= 1) {
        return true;
    }

    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    unordered_set<int> elements;

    for (int val : arr) {
        minVal = min(val, minVal);
        maxVal = max(val, maxVal);
        elements.insert(val);
    }

    int d = (maxVal - minVal) / (arr.size() - 1);

    for (size_t i = 0; i < arr.size(); ++i) {
        int ai = minVal + i * d;
        if (elements.find(ai) == elements.end()) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> arr = {17, 9, 5, 29, 1, 25, 13, 37, 21, 33};
    cout << (isArithmeticSequence(arr) ? "true" : "false") << endl;

    return 0;
}
