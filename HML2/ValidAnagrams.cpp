#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class ValidAnagrams {
public:
    static bool sol(const string& s1, const string& s2) {
        unordered_map<char, int> map;
        for (char ch : s1) {
            map[ch]++;
        }

        for (char ch : s2) {
            if (map.find(ch) == map.end()) {
                return false;
            } else if (map[ch] == 1) {
                map.erase(ch);
            } else {
                map[ch]--;
            }
        }
        return map.empty();
    }
};

int main() {
    string s1 = "abbcaad";
    string s2 = "babacda";
    cout << (ValidAnagrams::sol(s1, s2) ? "true" : "false") << std::endl;
    return 0;
}