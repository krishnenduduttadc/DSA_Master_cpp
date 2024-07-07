#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class ContainerMostWater {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int ans = INT_MIN; // Initialize ans with minimum integer value
        while (i < j) {
            int w = (j - i) * min(height[i], height[j]);
            ans = max(ans, w);
            if (height[i] <= height[j]) i++;
            else j--;
        }
        return ans;
    }
};

int main() {
    ContainerMostWater solution;

    // Hardcoded input array
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // Example input

    // Calling maxArea to find the maximum area of water that can be contained
    int maxWater = solution.maxArea(height);

    // Printing the maximum area
    cout << "Maximum area of water: " << maxWater << endl;

    return 0;
}
