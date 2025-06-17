#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool areAnagrams(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) return false;

    unordered_map<char, int> freq;

    for (char ch : s1) {
        freq[ch]++;
    }

    for (char ch : s2) {
        if (freq.find(ch) == freq.end()) {
            return false;
        } else if (freq[ch] == 1) {
            freq.erase(ch);
        } else {
            freq[ch]--;
        }
    }

    return freq.empty();
}

int main() {
    string s1 = "abbcaad";
    string s2 = "babacda";

    cout << (areAnagrams(s1, s2) ? "true" : "false") << endl;

    return 0;
}
