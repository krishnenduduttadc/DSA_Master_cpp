#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
using namespace std;

void solution(string str, int mra, unordered_set<string>& ans);
int getMin(string str);

void solution(string str, int mra, unordered_set<string>& ans) {
    if (mra == 0) {
        int mrnow = getMin(str);
        if (mrnow == 0) {
            if (ans.find(str) == ans.end()) {
                cout << str << endl;
                ans.insert(str);
            }
        }
        return;
    }
    for (int i = 0; i < str.length(); i++) {
        string left = str.substr(0, i);
        string right = str.substr(i + 1);
        solution(left + right, mra - 1, ans);
    }
}

int getMin(string str) {
    stack<char> st;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            if (st.empty()) {
                st.push(ch);
            } else if (st.top() == ')') {
                st.push(ch);
            } else if (st.top() == '(') {
                st.pop();
            }
        }
    }
    return st.size();
}

int main() {
    string str = "((((()))";
    unordered_set<string> ans;
    int mra = getMin(str);
    solution(str, mra, ans);
    return 0;
}
