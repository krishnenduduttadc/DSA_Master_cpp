#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_map<char, int> count;
    int dis = 0;
    int start = 0;
    int ans = 0;

    for (int i = 0; i < s.length(); i++) {
        int fre = count[s[i]];
        if (fre == 0) dis++;
        count[s[i]] = fre + 1;

        while (dis > 2) {
            fre = count[s[start]];
            count[s[start]] = fre - 1;
            if (fre - 1 == 0) {
                dis--;
            }
            start++;
        }

        ans = max(ans, i - start + 1);
    }

    return ans;
}

int main() {
    string s = "abccccccghi";
    cout << "Length of longest substring with at most two distinct characters in \"" << s << "\": " << lengthOfLongestSubstringTwoDistinct(s) << endl;
    return 0;
}
