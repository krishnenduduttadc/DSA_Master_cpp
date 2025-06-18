#include <iostream>
#include <string>
using namespace std;

bool isStringPalindrome(const string input, int s, int e) {
    if (s == e) {
        return true;
    }
    if (input[s] != input[e]) {
        return false;
    }
    if (s < e + 1) {
        return isStringPalindrome(input, s + 1, e - 1);
    }
    return true;
}

bool isStringPalindrome(const string& input) {
    int s = 0;
    int e = input.length() - 1;
    return isStringPalindrome(input, s, e);
}

int main() {
    cout << (isStringPalindrome("abba") ? "true" : "false") << endl;
    return 0;
}
