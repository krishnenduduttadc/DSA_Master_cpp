#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

// Function to get precedence of operators
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

// Function to convert infix expression to postfix expression
string infixToPostfix(const string& infix) {
    stack<char> operatorStack;
    string postfix;

    for (char c : infix) {
        int precedence = getPrecedence(c);

        if (isalnum(c)) {
            postfix.push_back(c);  // Add operand to postfix
        } else if (c == '(') {
            operatorStack.push(c);  // Push '(' onto stack
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix.push_back(operatorStack.top()); // Pop to postfix until '('
                operatorStack.pop();
            }
            operatorStack.pop(); // Remove the '('
        } else {
            while (!operatorStack.empty() && precedence <= getPrecedence(operatorStack.top())) {
                postfix.push_back(operatorStack.top()); // Pop to postfix based on precedence
                operatorStack.pop();
            }
            operatorStack.push(c);  // Push current operator onto stack
        }
    }

    // Pop all the remaining operators from the stack
    while (!operatorStack.empty()) {
        postfix.push_back(operatorStack.top());
        operatorStack.pop();
    }
    return postfix;  // Return the complete postfix expression
}

int main() {
    // Hardcoded infix expressions
    string infixExpressions[] = {
        "(a+(b*c))",
        "((a+b)*(z+x))",
        "((a+t)*((b+(a+c))^(c+d)))"
    };
    
    int t = sizeof(infixExpressions) / sizeof(infixExpressions[0]); // Number of test cases

    // Process each hardcoded infix expression
    for (int i = 0; i < t; i++) {
        string postfixExpression = infixToPostfix(infixExpressions[i]);
        cout << postfixExpression << "\n";  // Output the postfix expression
    }

    return 0;
}

/*
Expected Output:
abc*+
zx+ab*+
at+ac+bcd+^*
*/
