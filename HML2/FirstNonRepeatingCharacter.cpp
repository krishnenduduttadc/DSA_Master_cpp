#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int sol(string s) {
    unordered_map<char, int> fmap;

    // Build frequency map
    for (char c : s) {
        fmap[c]++;
    }

    // Find first non-repeating character
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (fmap[ch] == 1) {
            return i;
        }
    }

    return -1; // If no non-repeating character found
}

int main() {
    string s = "abbcaddecfab";
    cout << sol(s) << endl;
    return 0;
}
