#include <iostream>
#include <string>

using namespace std;

// Function to check if s3 is an interleaving of s1 and s2
bool is_interleave(const string &s1, const string &s2, const string &s3) {
    // Base case: if all strings are empty, return true
    if (s1.empty() && s2.empty() && s3.empty()) {
        return true;
    }

    // If s3 is empty but either s1 or s2 is not, return false
    if (s3.empty()) {
        return false;
    }

    // Recursive cases
    if (!s1.empty() && s1[0] == s3[0] && is_interleave(s1.substr(1), s2, s3.substr(1))) {
        return true;
    }

    if (!s2.empty() && s2[0] == s3[0] && is_interleave(s1, s2.substr(1), s3.substr(1))) {
        return true;
    }

    return false;
}

int main() {
    // Hardcoded input strings
    string s1 = "abc";
    string s2 = "def";
    string s3 = "adbcef";

    // Output result
    cout << (is_interleave(s1, s2, s3) ? "True" : "False") << endl;

    return 0;
}
