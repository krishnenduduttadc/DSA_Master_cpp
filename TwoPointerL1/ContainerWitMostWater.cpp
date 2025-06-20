#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxArea(vector<int> &height)
{
    int i = 0, j = height.size() - 1;
    int ans = INT_MIN; // Initialize ans with minimum integer value
    while (i < j)
    {
        int w = (j - i) * min(height[i], height[j]);
        ans = max(ans, w);
        if (height[i] <= height[j])
            i++;
        else
            j--;
    }
    return ans;
}

int main()
{

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // Example input
    int maxWater = maxArea(height);
    cout << "Maximum area of water: " << maxWater << endl;

    return 0;
}
