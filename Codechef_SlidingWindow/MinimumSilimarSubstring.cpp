#include <bits/stdc++.h>
using namespace std;


string findShortestSubstring(string s, string t) {
    unordered_map<char, int> requiredFreq;
    for (char c : t) {
        requiredFreq[c]++;
    }

    // Two pointers for the sliding window
    int left = 0, right = 0;
    int required = requiredFreq.size(); // Number of unique characters in t
    int formed = 0;  // Number of characters with the desired frequency in the current window
    unordered_map<char, int> windowFreq;  // Frequency of characters in the current window

    // Variables to track the minimum window
    int minLength = INT_MAX;
    int minLeft = 0, minRight = 0;

    // Sliding window
    while (right < s.length()) {
        char charRight = s[right];
        windowFreq[charRight]++;

        // If the current character's frequency matches the required frequency in t
        if (requiredFreq.count(charRight) > 0 && windowFreq[charRight] == requiredFreq[charRight]) {
            formed++;
        }

        // Try to shrink the window when it's valid (contains all characters of t)
        while (left <= right && formed == required) {
            if ((right - left + 1) < minLength) {
                minLength = right - left + 1;
                minLeft = left;
                minRight = right;
            }

            // Shrink the window from the left
            char charLeft = s[left];
            windowFreq[charLeft]--;
            if (requiredFreq.count(charLeft) > 0 && windowFreq[charLeft] < requiredFreq[charLeft]) {
                formed--;
            }

            left++;
        }

        // Expand the window by moving the right pointer
        right++;
    }

    // Check if a valid window was found
    if (minLength == INT_MAX) {
        return "IMPOSSIBLE";
    } else {
        return s.substr(minLeft, minLength);
    }
    }
    
    
    
int main() {
	int m, n;
    cin >> m >> n;   // Read the lengths of the strings S and T
    string s, t;
    cin >> s >> t;  
    string result = findShortestSubstring(s, t);
    if (result == "IMPOSSIBLE") {
        cout << result << endl;
    } else {
        cout << result.length() << endl;
        cout << result << endl;
    }

}


/*
8 2
aabcbcde
ad
*/