#include <iostream>
#include <string>

using namespace std;

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
    string s1, s2, s3;

    // Input strings
    cin >> s1 >> s2 >> s3;

    // Output result
    cout << (is_interleave(s1, s2, s3) ? "True" : "False") << endl;

    return 0;
}



/*
abc
def
adbcef

*/