#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countCommonElements(vector<int>& A, vector<int>& B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int i = 0, j = 0, count = 0;

    while (i < A.size() && j < B.size()) {
        if (A[i] == B[j]) {
            count++;
            i++;
            j++;
        } else if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    }
    return count;
}

int main() {
    vector<pair<vector<int>, vector<int>>> test_cases = {
        {{1, 2, 3, 4}, {1, 3, 4, 5}},
        {{2, 4, 1}, {1, 4, 2}},
        {{2}, {3}}
    };

    for (auto& test_case : test_cases) {
        vector<int>& A = test_case.first;
        vector<int>& B = test_case.second;
        cout << countCommonElements(A, B) << endl;
    }

    return 0;
}
