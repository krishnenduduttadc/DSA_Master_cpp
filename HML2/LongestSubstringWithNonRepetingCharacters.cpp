#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int longestSubstringWithoutRepeatingChars(const string& str) {
    int ans = 0;
    int i = -1, j = -1;
    unordered_map<char, int> freq;

    while (true) {
        bool f1 = false, f2 = false;

        while (i < (int)str.length() - 1) {
            f1 = true;
            i++;
            char ch = str[i];
            freq[ch]++;

            if (freq[ch] == 2) {
                break;
            } else {
                ans = max(ans, i - j);
            }
        }

        while (j < i) {
            f2 = true;
            j++;
            char ch = str[j];
            freq[ch]--;
            if (freq[ch] == 1) {
                break;
            }
        }

        if (!f1 && !f2) break;
    }

    return ans;
}

int main() {
    string str = "aabcbcdbca";
    cout << longestSubstringWithoutRepeatingChars(str) << endl;
    return 0;
}
