#include <iostream>
#include <stack>
#include <string>
using namespace std;

int performOperation(int a, int b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    else if (op == '/') return a / b;
    return 0;
}

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    return 0;
}

int calculate(const string& s) {
    stack<int> operand;
    stack<char> oper;
    int i = 0;

    while (i < s.length()) {
        char ch = s[i];

        if (isdigit(ch)) {
            int num = 0;
            while (i < s.length() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            operand.push(num);
            i--; // adjust because the loop will increment i again
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!oper.empty() && precedence(oper.top()) >= precedence(ch)) {
                char op = oper.top(); oper.pop();
                int val2 = operand.top(); operand.pop();
                int val1 = operand.top(); operand.pop();
                operand.push(performOperation(val1, val2, op));
            }
            oper.push(ch);
        }
        i++;
    }

    while (!oper.empty()) {
        char op = oper.top(); oper.pop();
        int val2 = operand.top(); operand.pop();
        int val1 = operand.top(); operand.pop();
        operand.push(performOperation(val1, val2, op));
    }

    return operand.top();
}

int main() {
    string expression1 = "3+2*2";
    cout << "Result of '" << expression1 << "' = " << calculate(expression1) << endl; // Expected: 7

    string expression2 = " 3/2 ";
    cout << "Result of '" << expression2 << "' = " << calculate(expression2) << endl; // Expected: 1

    string expression3 = " 3+5 / 2 ";
    cout << "Result of '" << expression3 << "' = " << calculate(expression3) << endl; // Expected: 5

    return 0;
}
