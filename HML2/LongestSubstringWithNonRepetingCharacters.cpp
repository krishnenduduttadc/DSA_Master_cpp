#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class LongestSubstringWithNonRepeatingCharacters {
public:
    static int solution(const string& str) {
        int ans = 0;
        int i = -1;
        int j = -1;

        unordered_map<char, int> map;
        while (true) {
            bool f1 = false;
            bool f2 = false;

            while (i < static_cast<int>(str.length()) - 1) {
                f1 = true;
                i++;
                char ch = str[i];
                map[ch]++;

                if (map[ch] == 2) {
                    break;
                } else {
                    int len = i - j;
                    if (len > ans) {
                        ans = len;
                    }
                }
            }

            while (j < i) {
                f2 = true;
                j++;
                char ch = str[j];
                map[ch]--;
                if (map[ch] == 1) {
                    break;
                }
            }

            if (!f1 && !f2) {
                break;
            }
        }

        return ans;
    }
};

int main() {
    string str = "aabcbcdbca";
    cout << LongestSubstringWithNonRepeatingCharacters::solution(str) << std::endl;
    return 0;
}