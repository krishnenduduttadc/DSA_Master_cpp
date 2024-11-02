#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<int>> test_cases = {
        {2, 5, 10},
        {4, 1, 5, 5, 10},
        {5, 4, 4, 6, 6, 8}
    };

    for (const auto& test_case : test_cases) {
        int N = test_case[0];
        vector<int> A(test_case.begin() + 1, test_case.end());

        sort(A.begin(), A.end());
        vector<int> unique_elements;
        if (N > 0) {
            unique_elements.push_back(A[0]);
        }
        for (int i = 1; i < N; i++) {
            if (A[i] != A[i - 1]) {
                unique_elements.push_back(A[i]);
            }
        }
        
        // Output the size of unique elements
        cout << unique_elements.size() << endl;
        
        // Output the unique elements
        for (const int &num : unique_elements) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
