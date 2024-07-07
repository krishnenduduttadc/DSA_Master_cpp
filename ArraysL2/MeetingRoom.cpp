#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool meetingRooms(vector<vector<int>>& intervals) {
    // Sort intervals based on their start times
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    // Check for overlapping intervals
    if (intervals.size() <= 1) {
        return true;
    }

    int end_time = intervals[0][1];

    for (int j = 1; j < intervals.size(); j++) {
        if (intervals[j][0] < end_time) {
            return false; // Overlapping intervals found
        } else {
            end_time = intervals[j][1];
        }
    }

    return true; // No overlapping intervals found
}

int main() {
    vector<vector<int>> input = {
        {1, 3},
        {8, 10},
        {7, 8},
        {9, 15},
        {2, 6}
    };

    bool res = meetingRooms(input);
    cout << (res ? "true" : "false") << endl;

    return 0;
}
