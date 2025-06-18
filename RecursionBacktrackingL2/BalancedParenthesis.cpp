#include <bits/stdc++.h>

using namespace std;

vector<string> generateParenthesisHelper(int open, int close, string current) {
    if (open == 0 && close == 0) {
        return {current}; 
    }
    
    vector<string> result;
    
    if (open > 0) {
        vector<string> left = generateParenthesisHelper(open - 1, close, current + "(");
        result.insert(result.end(), left.begin(), left.end());
    }
    
    if (close > open) {
        vector<string> right = generateParenthesisHelper(open, close - 1, current + ")");
        result.insert(result.end(), right.begin(), right.end());
    }
    
    return result;
}

vector<string> generateParenthesis(int n) {
    return generateParenthesisHelper(n, n, "");
}

int main() {
    int n = 3;
    vector<string> result = generateParenthesis(n);
    sort(result.begin(), result.end()); 
    for (const string s : result) {
        cout << s << endl;
    }
    return 0;
}
