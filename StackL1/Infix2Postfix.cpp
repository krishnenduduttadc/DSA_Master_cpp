#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to get precedence of operators
static int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}
// Function to convert infix expression to postfix expression
static string infixToPostfix(string exp)
{
    stack<string> operand;
    stack<char> operatorStack;
    int i = 0;
    while (i < exp.length())
    {
        char ch = exp[i];
        if (ch == '(')
        {
            operatorStack.push(ch);
        }
        else if (ch == ')')
        {
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                char oper = operatorStack.top();
                operatorStack.pop();
                string val2 = operand.top();
                operand.pop();
                string val1 = operand.top();
                operand.pop();
                string cal = val1 + val2 + oper;
                operand.push(cal);
            }
            operatorStack.pop(); // Pop '(' from stack
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(ch))
            {
                char oper = operatorStack.top();
                operatorStack.pop();
                string val2 = operand.top();
                operand.pop();
                string val1 = operand.top();
                operand.pop();
                string cal = val1 + val2 + oper;
                operand.push(cal);
            }
            operatorStack.push(ch);
        }
        else
        {
            operand.push(string(1, ch));
        }
        i++;
    }
    while (!operatorStack.empty())
    {
        char oper = operatorStack.top();
        operatorStack.pop();
        string val2 = operand.top();
        operand.pop();
        string val1 = operand.top();
        operand.pop();
        string cal = val1 + val2 + oper;
        operand.push(cal);
    }
    return operand.top();
}

int main()
{
    string infix1 = "a+b*c";
    string postfix1 = infixToPostfix(infix1);
    cout << "Infix: " << infix1 << " -> Postfix: " << postfix1 << endl; // Expected: "abc*+"

    return 0;
}
