#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    int i = 0;
    int j = s.length() - 1;
    while (i <= j) {
        if (s[i] != s[j]) {
            return false;
        } else {
            i++;
            j--;
        }
    }
    return true;
}

void solution(string str) {
    for (int i = 0; i < str.length(); i++) {
        for (int j = i + 1; j <= str.length(); j++) {
            string ss = str.substr(i, j - i);
            if (isPalindrome(ss)) {
                cout << ss << "\n";
            }
        }
    }
}

int main() {
    string str = "abcc";
    solution(str);
    return 0;
}
