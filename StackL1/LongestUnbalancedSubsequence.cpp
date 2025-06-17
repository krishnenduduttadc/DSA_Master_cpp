#include <iostream>
#include <stack>
#include <string>
using namespace std;

static bool isValid(string s)
{
    stack<char> stack;
    int i = 0;

    while (i < s.length())
    {
        char ch = s[i];
        if (stack.empty() || ch == '(' || ch == '[' || ch == '{')
        {
            stack.push(ch);
        }
        else
        {
            if ((ch == ')' && stack.top() == '(') || (ch == ']' && stack.top() == '[') || (ch == '}' && stack.top() == '{'))
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
        i++;
    }

    return stack.empty();
}

static int longestUnbalancedSubsequenceLength(string s)
{
    int len = s.length();
    if (isValid(s))
    {
        return len - 1;
    }
    else
    {
        return len;
    }
}

int main()
{
    string s = "{[()]}"; // Example input, change as needed

    int result = longestUnbalancedSubsequenceLength(s);
    cout << "Length of the longest unbalanced subsequence: " << result << endl;

    return 0;
}
