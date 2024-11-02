#include <iostream>
using namespace std;

// Function to check if a string is a palindrome
string checkPalindrome(string s, int n) {
    // If n exceeds half the length of the string, it means all checks passed
    if (n >= s.length() / 2) {
        return "Yes"; // String is a palindrome
    }
    // Check characters from the start and end
    if (s[n] != s[s.length() - n - 1]) {
        return "No"; // Characters do not match, not a palindrome
    }
    // Recursive call to check the next pair of characters
    return checkPalindrome(s, n + 1);
}

int main() {
    // Hardcoded string to be checked
    string s = "tenet"; // Example input

    cout << checkPalindrome(s, 0) << endl; // Output the result
    return 0;
}
