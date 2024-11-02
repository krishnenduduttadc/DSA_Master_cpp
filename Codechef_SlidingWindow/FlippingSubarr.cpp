#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<int>> test_cases = {
        {3, 0, 1, 0}
    };

    for (auto& test_case : test_cases) {
        int n = test_case[0];
        vector<int> arr(test_case.begin() + 1, test_case.end());

        int current = 0, count = 0;
        vector<int> freq;
        for(int i = 0; i < n; i++) {
            if(arr[i] != current) {
                current = arr[i];
                freq.push_back(count);
                count = 0;
            }
            count++;
        }
        freq.push_back(count);

        long long maximum = INT_MIN;
        for(int i = 0; i < freq.size(); i++) {
            long long sum = 0;
            if(i % 2 != 0) sum = freq[i];
            else {
                sum = freq[i];
                if(i > 0) sum += freq[i-1];
                if(i < freq.size() - 1) sum += freq[i+1];
            }
            maximum = max(maximum, sum);
        }

        if(freq.size() == 2 && freq[0] == 0) {
            cout << n - 1 << endl;
        } else {
            cout << maximum << endl;
        }
    }

    return 0;
}
