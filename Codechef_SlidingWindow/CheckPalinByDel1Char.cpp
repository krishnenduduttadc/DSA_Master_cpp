#include <iostream>

#include <string>

using namespace std;


bool isPalindrome(const string & s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
bool validPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
        left++;
        right--;
    }
    return true;

}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << (validPalindrome(s) ? "true" : "false") << endl;
    return 0;
}

/*
4
abca

*/