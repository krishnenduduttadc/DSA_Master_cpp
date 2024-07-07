#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minArrows(vector<vector<int>>& coordinates) {
    // Sort the balloons by their end coordinates
    sort(coordinates.begin(), coordinates.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int arrows = 1; // Initial arrow count
    int end = coordinates[0][1]; // End of the first balloon

    // Traverse through all balloons
    for (int i = 1; i < coordinates.size(); i++) {
        // If the current balloon starts after the previous end, increment arrows count and update end
        if (coordinates[i][0] > end) {
            arrows++;
            end = coordinates[i][1];
        }
    }

    return arrows;
}

int main() {
    vector<vector<int>> coordinates = {
        {1, 3},
        {4, 5}
    };

    cout << minArrows(coordinates) << endl;

    return 0;
}
