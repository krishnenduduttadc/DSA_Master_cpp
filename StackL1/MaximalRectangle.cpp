#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> s;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; ++i)
    {
        int temp = (i < n) ? heights[i] : 0;
        while (!s.empty() && temp < heights[s.top()])
        {
            int tbs = s.top();
            s.pop();
            int nsr = i;
            int x1 = nsr - 1;
            int nsl = s.empty() ? -1 : s.top();
            int x2 = nsl + 1;
            int area = heights[tbs] * (x1 - x2 + 1);
            maxArea = max(maxArea, area);
        }
        s.push(i);
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.empty())
        return 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> heights(m, 0);
    int maxArea = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i == 0)
            {
                heights[j] = matrix[i][j] - '0';
            }
            else
            {
                if (matrix[i][j] == '1')
                {
                    heights[j] += matrix[i][j] - '0';
                }
                else
                {
                    heights[j] = 0;
                }
            }
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}

int main()
{
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    int maxRectangle = maximalRectangle(matrix);
    cout << "The area of the largest rectangle is: " << maxRectangle << endl;

    return 0;
}
