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
            return result;
        } else {
            result += c;
        }
        index++;
    }
    return result;
}

string flattenString(const string &s) {
    int index = 0;
    return flattenString(s, index);
}

int main() {
    string s;
    cin >> s;
    cout << flattenString(s);
    return 0;
}



/*
abc(def(ghi(jkl(mn))))op
*/