#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int t = 3; // Number of test cases
    string testCases[] = {"aba", "abac", "abcd"}; // Hardcoded test cases

    for (int k = 0; k < t; k++) {
        string s = testCases[k];
        int l = s.length();
        bool flag = true;
        int cnt1 = 0, cnt2 = 0;

        if (l <= 1) {
            cout << "NO" << endl;
        } else if (l % 2 == 0) {
            for (int i = 0, j = l / 2; i < l / 2 && j < l; i++, j++) {
                if (s[i] != s[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            for (int i = l / 2, j = 0; i < l && j < l / 2; i++) {
                if (s[i] == s[j]) {
                    j++;
                    cnt1++;
                }
            }

            for (int i = 0, j = l / 2 + 1; i <= l / 2 && j < l; i++) {
                if (s[i] == s[j]) {
                    j++;
                    cnt2++;
                }
            }

            if (cnt1 == l / 2 || cnt2 == l / 2) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
