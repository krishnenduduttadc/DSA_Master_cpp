#include <iostream>
#include <stack>
#include <vector>
using namespace std;


    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int ans = 0;
        for (int i = 0; i <= heights.size(); i++) {
            int temp = (i != heights.size()) ? heights[i] : 0;
            while (!s.empty() && temp < heights[s.top()]) {
                int tbs = s.top();
                s.pop();
                int nsr = i;
                int x1 = nsr - 1;
                int nsl = (s.empty()) ? -1 : s.top();
                int x2 = nsl + 1;
                int area = heights[tbs] * (x1 - x2 + 1);
                ans = max(ans, area);
            }
            s.push(i);
        }
        return ans;
    }


int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int maxArea = largestRectangleArea(heights);
    cout << "The largest rectangle area is: " << maxArea << endl;
    return 0;
}
