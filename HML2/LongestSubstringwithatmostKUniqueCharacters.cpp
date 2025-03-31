#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class LongestSubstringWithAtMostKUniqueCharacters {
public:
    static int sol(const std::string& str, int k) {
        int ans = 0;
        int i = -1;
        int j = -1;
        std::unordered_map<char, int> map;
        
        while (true) {
            bool f1 = false;
            bool f2 = false;
            
            while (i < static_cast<int>(str.length()) - 1) {
                f1 = true;
                i++;
                char ch = str[i];
                map[ch]++;
                
                if (map.size() <= k) {
                    int len = i - j;
                    if (len > ans) {
                        ans = len;
                    }
                } else {
                    break;
                }
            }

            while (j < i) {
                f2 = true;
                j++;
                char ch = str[j];
                if (map[ch] == 1) {
                    map.erase(ch);
                } else {
                    map[ch]--;
                }

                if (map.size() > k) {
                    continue;
                } else {
                    int len = i - j;
                    if (len > ans) {
                        ans = len;
                    }
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
    string str = "ddacbbaccdedacebb";
    int k = 3;
    cout << LongestSubstringWithAtMostKUniqueCharacters::sol(str, k) << std::endl;
    return 0;
}