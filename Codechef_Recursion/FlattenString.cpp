#include <bits/stdc++.h>
using namespace std;

string flattenString(const std::string &s, int &index) {
    string result;
    while (index < s.length()) {
        char c = s[index];
        if (c == '(') {
            index++;
            result += flattenString(s, index);
        } else if (c == ')') {
            return result; // Return the result when we hit a closing parenthesis
        } else {
            result += c; // Append the character to the result
        }
        index++;
    }
    return result;
}

string flattenString(const string &s) {
    int index = 0; // Initialize the index for the recursive function
    return flattenString(s, index);
}

int main() {
    string s = "abc(def(ghi(jkl(mn))))op"; // Hardcoded input
    cout << flattenString(s) << endl; // Output the flattened string
    return 0;
}
