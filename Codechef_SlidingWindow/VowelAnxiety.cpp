#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, string>> test_cases = {
        {10, "abcdefghij"},
        {7, "bcadage"}
    };

    for (const auto& test_case : test_cases) {
        int n = test_case.first;
        string s = test_case.second;

        // Vowels set
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        vector<char> result(n);
        int left = 0;
        int right = n - 1;
        bool startFromLeft = false;
        
        // Traverse from end to start
        for(int i = n - 1; i >= 0; i--) {
            if(startFromLeft) {
                result[left++] = s[i];
            } else {
                result[right--] = s[i];
            }
            
            if(vowels.find(s[i]) != vowels.end()) {
                startFromLeft = !startFromLeft;
            }
        }
        
        for(int i = 0; i < n; i++) {
            cout << result[i];
        }
        cout << '\n';
    }

    return 0;
}
