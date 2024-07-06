#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to convert a prefix expression to a postfix expression.
string preToPost(string exp) {
    stack<string> op;
    int n = exp.length();
    for (int i = n - 1; i >= 0; i--) {
        char ch = exp[i];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            string val1 = op.top();
            op.pop();
            string val2 = op.top();
            op.pop();
            string cal = val1 + val2 + ch;
            op.push(cal);
        } else {
            op.push(string(1, ch));
        }
    }
    return op.top();
}

int main() {
    string prefix1 = "*+AB-CDE";
    cout << "Prefix: " << prefix1 << " -> Postfix: " << preToPost(prefix1) << endl; // Expected: "ABC+DE-*"

    string prefix2 = "*-A/BC-/DEFG";
    cout << "Prefix: " << prefix2 << " -> Postfix: " << preToPost(prefix2) << endl; // Expected: "ABC/-DE/FG-*"

    // Add more test cases as needed

    return 0;
}
