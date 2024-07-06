#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstringTwoDistinct(string s) {
    int maxLength = 0;
    unordered_map<char, int> map;
    
    for (int j = 0, i = 0; i < s.length(); i++) {
        char currentChar = s[i];
        
        // Acquire: Add current character to the window
        map[currentChar]++;
        
        // Release: If window contains more than two distinct characters, move the start pointer forward until the window contains at most two distinct characters
        while (map.size() > 2) {
            char charToRemove = s[j];
            map[charToRemove]--;
            if (map[charToRemove] == 0) {
                map.erase(charToRemove);
            }
            j++;
        }
        
        maxLength = max(maxLength, i - j + 1);
    }
    
    return maxLength;
}

int main() {
    string str1 = "eceba";
    string str2 = "ccaabbb";
    
    cout << "Longest substring with at most two distinct characters in \"" << str1 << "\": " << lengthOfLongestSubstringTwoDistinct(str1) << endl;
    cout << "Longest substring with at most two distinct characters in \"" << str2 << "\": " << lengthOfLongestSubstringTwoDistinct(str2) << endl;
    
    return 0;
}
