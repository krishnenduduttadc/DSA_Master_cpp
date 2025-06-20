#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int longestSubstringWithKUniqueChars(const string& str, int k) {
    int ans = 0;
    int i = -1, j = -1;
    unordered_map<char, int> freq;

    while (true) {
        bool f1 = false, f2 = false;

        while (i < (int)str.length() - 1) {
            f1 = true;
            i++;
            freq[str[i]]++;

            if (freq.size() <= k) {
                ans = max(ans, i - j);
            } else {
                break;
            }
        }

        while (j < i) {
            f2 = true;
            j++;
            char ch = str[j];
            if (freq[ch] == 1) freq.erase(ch);
            else freq[ch]--;

            if (freq.size() <= k) {
                ans = max(ans, i - j);
                break;
            }
        }

        if (!f1 && !f2) break;
    }

    return ans;
}

int main() {
    string str = "ddacbbaccdedacebb";
    int k = 3;
    cout << longestSubstringWithKUniqueChars(str, k) << endl;
    return 0;
}
