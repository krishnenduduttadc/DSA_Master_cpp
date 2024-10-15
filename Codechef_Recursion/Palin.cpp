#include <iostream>
using namespace std;

string checkPalindrome(string s, int n) {
    if (n > s.length() / 2) {
        return "Yes";
    }
    if (s[n] != s[s.length() - n - 1]) {
        return "No";
    }
    return checkPalindrome(s, n + 1);
}

int main() {
    string s;
    cin >> s;
    cout << checkPalindrome(s, 0) << endl;
    return 0;
}


/*
tenet
*/