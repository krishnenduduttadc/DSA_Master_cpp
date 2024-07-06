#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Calculator {
public:
    int calculate(string s) {
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
                i--;
            } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                while (!oper.empty() && precedence(oper.top()) >= precedence(ch)) {
                    char op = oper.top();
                    oper.pop();
                    int val2 = operand.top();
                    operand.pop();
                    int val1 = operand.top();
                    operand.pop();
                    int cal = performOperation(val1, val2, op);
                    operand.push(cal);
                }
                oper.push(ch);
            }
            i++;
        }
        while (!oper.empty()) {
            char op = oper.top();
            oper.pop();
            int val2 = operand.top();
            operand.pop();
            int val1 = operand.top();
            operand.pop();
            int cal = performOperation(val1, val2, op);
            operand.push(cal);
        }
        return operand.top();
    }

private:
    int performOperation(int a, int b, char c) {
        if (c == '+') return a + b;
        else if (c == '-') return a - b;
        else if (c == '*') return a * b;
        else if (c == '/') return a / b;
        return 0; // Handle invalid operations
    }

    int precedence(char c) {
        if (c == '*' || c == '/') return 2;
        else if (c == '+' || c == '-') return 1;
        else return 0;
    }
};

int main() {
    Calculator calc;

    string expression1 = "3+2*2";
    cout << "Result of '" << expression1 << "' = " << calc.calculate(expression1) << endl; // Expected: 7

    string expression2 = " 3/2 ";
    cout << "Result of '" << expression2 << "' = " << calc.calculate(expression2) << endl; // Expected: 1

    string expression3 = " 3+5 / 2 ";
    cout << "Result of '" << expression3 << "' = " << calc.calculate(expression3) << endl; // Expected: 5

    // Add more test cases as needed

    return 0;
}
