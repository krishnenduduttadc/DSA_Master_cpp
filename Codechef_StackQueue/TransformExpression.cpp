#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

string infixToPostfix(const string& infix) {
    stack<char> operatorStack;
    string postfix;

    for (char c : infix) {
        int precedence = getPrecedence(c);

        if (isalnum(c)) {
            postfix.push_back(c);
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix.push_back(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.pop(); // Remove the '('
        } else {
            while (!operatorStack.empty() && precedence <= getPrecedence(operatorStack.top())) {
                postfix.push_back(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty()) {
        postfix.push_back(operatorStack.top());
        operatorStack.pop();
    }
    return postfix;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string infixExpression;
        cin >> infixExpression;
        string postfixExpression = infixToPostfix(infixExpression);
        cout << postfixExpression << "\n";
    }

    return 0;
}


/*
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))
*/