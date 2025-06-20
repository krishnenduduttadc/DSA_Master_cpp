#include <iostream>
#include <stack>
using namespace std;

int evaluatePostFix(string S) {
    stack<int> op;
    for (int i = 0; i < S.length(); i++) {
        char ch = S[i];
        if (ch == '*' || ch == '/' || ch == '+' || ch == '-') {
            int val2 = op.top();
            op.pop();
            int val1 = op.top();
            op.pop();
            int c = 0;
            if (ch == '+') c = val1 + val2;
            else if (ch == '-') c = val1 - val2;
            else if (ch == '*') c = val1 * val2;
            else if (ch == '/') c = val1 / val2;
            op.push(c);
        } else {
            op.push(ch - '0');
        }
    }
    return op.top();
}

int main() {
    string postfix1 = "231*+9-";
    cout << "Postfix: " << postfix1 << " -> Result: " << evaluatePostFix(postfix1) << endl; // Expected: 4

    return 0;
}
