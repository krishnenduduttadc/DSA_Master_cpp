#include <iostream>
#include <string>
using namespace std;

// Function to find the length of the longest palindromic subsequence
int longestPalindromicSubsequence(string s, int start, int end) {
    // Base cases
    if (start > end) return 0; // If the start index is greater than the end, return 0
    if (start == end) return 1; // A single character is a palindrome of length 1

    // If the characters at the start and end indices match
    if (s[start] == s[end]) {
        return 2 + longestPalindromicSubsequence(s, start + 1, end - 1);
    } else {
        // If the characters do not match, we have two options:
        // 1. Exclude the current start character and recurse
        // 2. Exclude the current end character and recurse
        return max(longestPalindromicSubsequence(s, start + 1, end),
                   longestPalindromicSubsequence(s, start, end - 1));
    }
}

int main() {
    // Hardcoded input string
    string s = "agbdba";

    int length = s.length();
    int result = longestPalindromicSubsequence(s, 0, length - 1);
    cout << result << endl; // Output the length of the longest palindromic subsequence

    return 0;
}
