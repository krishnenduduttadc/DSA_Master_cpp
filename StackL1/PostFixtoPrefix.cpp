#include <iostream>
#include <stack>
using namespace std;

// Function to convert a postfix expression to a prefix expression.
string postToPre(string exp) {
    stack<string> op;
    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            string val2 = op.top();
            op.pop();
            string val1 = op.top();
            op.pop();
            string cal = ch + val1 + val2;
            op.push(cal);
        } else {
            op.push(string(1, ch));
        }
    }
    return op.top();
}

int main() {
    string postfix1 = "ab+c*";
    cout << "Postfix: " << postfix1 << " -> Prefix: " << postToPre(postfix1) << endl; // Expected: "*+abc"

    return 0;
}
