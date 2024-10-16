#include <bits/stdc++.h>

using namespace std;

bool lower(string s) {
    for (char c: s) {
        if (islower(c)) {
            return true;
        }
    }
    return false;
}

bool upper(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (isupper(s[i])) {
            return true;
        }
    }
    return false;
}

bool digit(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            return true;
        }
    }
    return false;
}

bool containsSpecialChar(const std::string & password) {
    set<char> specialChars = {
        '@',
        '#',
        '%',
        '&',
        '?'
    };
    for (char ch: password) {
        if (specialChars.find(ch) != specialChars.end()) {
            return true;
        }
    }
    return false;
}

bool slen(string s) {
    return s.length() >= 10;  // Simplified to return the boolean directly
}

int main() {
   
    int T = 5;  

   
    vector<string> testCases = {
        "A1b@CdeFG",  
        "abcdefghij", 
        "U@code4CHEFINA",  
        "abc1&defgh",  
        "Abc123456"    
    };

    // Iterate over each test case
    for (int i = 0; i < T; i++) {
        string S = testCases[i]; 

        // Extracting middle characters
        string smid = S.substr(1, S.length() - 2);
        if (lower(S) && upper(smid) && digit(smid) && containsSpecialChar(smid) && slen(S)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
