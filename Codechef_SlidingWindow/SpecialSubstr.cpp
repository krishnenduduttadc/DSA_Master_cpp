#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, string>> test_cases = {
        {6, "jyjerm"},
        {4, "abbb"}
    };

    for (const auto& [n, s] : test_cases) {
        vector<int> freq(26, 0);
        int start = 0, maxLength = 0;
        
        for (int end = 0; end < n; ++end) {
            int idx = s[end] - 'a';
            freq[idx]++;
            
            // If the count exceeds the allowed frequency, shrink the window from the left
            while (freq[idx] > idx + 1) {
                freq[s[start] - 'a']--;
                start++;
            }
            
            // Calculate the maximum length of the valid substring
            maxLength = max(maxLength, end - start + 1);
        }
        
        cout << maxLength << "\n";
    }

    return 0;
}
