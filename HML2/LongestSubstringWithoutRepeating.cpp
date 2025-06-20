#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    unordered_map<char, int> map;

    for (int start = 0, end = 0; end < s.length(); end++) {
        char currentChar = s[end];

        if (map.find(currentChar) != map.end()) {
            start = max(map[currentChar] + 1, start);
        }

        maxLength = max(maxLength, end - start + 1);

        map[currentChar] = end;
    }

    return maxLength;
}

int main() {
    string str1 = "abcabcbb";
    string str2 = "bbbbb";
    string str3 = "pwwkew";

    cout << "Longest substring without repeating characters in \"" << str1 << "\": " << lengthOfLongestSubstring(str1) << endl;
    cout << "Longest substring without repeating characters in \"" << str2 << "\": " << lengthOfLongestSubstring(str2) << endl;
    cout << "Longest substring without repeating characters in \"" << str3 << "\": " << lengthOfLongestSubstring(str3) << endl;

    return 0;
}
