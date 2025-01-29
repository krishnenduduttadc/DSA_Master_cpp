#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int solution(const string str) {
    int ans = 0;
    int i = -1;
    int j = -1;
    unordered_map<char, int> map;

    while (true) {
        bool f1 = false;
        bool f2 = false;

        while (i < str.length() - 1) {
            f1 = true;
            i++;
            char ch = str[i];
            map[ch] = map[ch] + 1; // Increment frequency count
            if (map[ch] == 2) {
                break;
            } else {
                ans += i - j;
            }
        }

        while (j < i) {
            f2 = true;
            j++;
            char ch = str[j];
            map[ch] = map[ch] - 1; // Decrement frequency count
            if (map[ch] == 1) {
                ans += i - j;
                break;
            }
        }

        if (!f1 && !f2) {
            break;
        }
    }

    return ans;
}

int main() {
    string str = "aabcbcdbca";
    cout << solution(str) << endl;
    return 0;
}
