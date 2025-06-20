#include <bits/stdc++.h>
using namespace std;

void permutation(int cb, int nboxes, vector<int> arr, vector<bool> used,
                 vector<int>& current, set<vector<int>>& allPermutations) {
    if (cb == nboxes) {
        allPermutations.insert(current);
        return;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (!used[i]) {
            if (i > 0 && arr[i] == arr[i - 1] && !used[i - 1]) {
                continue;
            }
            used[i] = true;
            current.push_back(arr[i]);
            permutation(cb + 1, nboxes, arr, used, current, allPermutations);
            current.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    vector<vector<int>> testCases = {
        {1, 1, 2},
        {2, 2}
    };

    for (const auto& A : testCases) {
        int N = A.size();
        vector<int> arr = A;
        sort(arr.begin(), arr.end());

        vector<bool> used(N, false);
        vector<int> current;
        set<vector<int>> allPermutations;
        permutation(0, N, arr, used, current, allPermutations);

        cout << allPermutations.size() << endl;
        for (const auto& perm : allPermutations) {
            for (int num : perm) {
                cout << num << " ";
            }
            cout << endl;
        }
        cout << "-----" << endl;
    }

    return 0;
}
