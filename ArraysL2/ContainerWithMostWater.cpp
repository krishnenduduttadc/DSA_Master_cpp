#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& heights) {
    int i = 0;
    int j = heights.size() - 1;
    int water = 0;
    while (i < j) {
        int w = j - i;
        int h = min(heights[i], heights[j]);
        water = max(water, h * w);
        if (heights[i] < heights[j]) {
            i++;
        } else {
            j--;
        }
    }

    return water;
}

int main() {
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int res = maxArea(heights);
    cout << res << endl;
    return 0;
}
