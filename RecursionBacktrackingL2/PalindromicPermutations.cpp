#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm> // Required for std::reverse

using namespace std;

void sol(int cs, int ts, unordered_map<char, int>& fmap, char oddc, string& asf) {
    if (cs > ts) {
        string rev = asf;
        reverse(rev.begin(), rev.end());
        string res = asf;
        if (oddc != '\0') {
            res += oddc;
        }
        res += rev;
        cout << res << endl;
        return;
    }
    for (auto& pair : fmap) {
        char ch = pair.first;
        int freq = pair.second;
        if (freq > 0) {
            fmap[ch]--;
            asf.push_back(ch);
            sol(cs + 1, ts, fmap, oddc, asf);
            asf.pop_back();
            fmap[ch]++;
        }
    }
}

void generatePalindromicPermutations(string str) {
    unordered_map<char, int> fmap;
    for (char ch : str) {
        fmap[ch]++;
    }

    char oddc = '\0'; // Character with odd frequency
    int odds = 0;     // Count of characters with odd frequencies
    int len = 0;      // Length of half of the palindrome
    for (auto& pair : fmap) {
        char ch = pair.first;
        int freq = pair.second;
        if (freq % 2 == 1) {
            oddc = ch;
            odds++;
        }
        fmap[ch] = freq / 2;
        len += freq / 2;
    }

    if (odds > 1) {
        cout << -1 << endl;
        return;
    }

    string asf = "";
    sol(1, len, fmap, oddc, asf);
}

int main() {
    string str = "aabbc";
    generatePalindromicPermutations(str);
    return 0;
}
