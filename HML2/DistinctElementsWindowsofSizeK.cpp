#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>

using namespace std;

vector<int> distinctElementsInWindow(const vector<int> arr, int k) {
    vector<int> result;
    unordered_map<int, int> frequencyMap;
    int n = arr.size();
    int i = 0;

    for (i = 0; i < k - 1; ++i) {
        frequencyMap[arr[i]]++;
    }

    for (int j = -1; i < n; ++i, ++j) {
        frequencyMap[arr[i]]++;

        result.push_back(frequencyMap.size());

        if (j >= 0) {
            if (frequencyMap[arr[j]] == 1) {
                frequencyMap.erase(arr[j]);
            } else {
                frequencyMap[arr[j]]--;
            }
        }
    }

    return result;
}

int main() {
    vector<int> arr = {2, 5, 5, 6, 3, 2, 3, 2, 4, 5, 2, 2, 2, 2, 3, 6};
    int k = 4;
    vector<int> result = distinctElementsInWindow(arr, k);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
