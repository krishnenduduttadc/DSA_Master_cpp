#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxActivity(vector<pair<int, int>>& activities) {
    // Sort by finish time (second element of pair)
    sort(activities.begin(), activities.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int res = 1;  // Always select the first activity
    int prev = 0;

    for (int curr = 1; curr < activities.size(); ++curr) {
        if (activities[curr].first >= activities[prev].second) {
            res++;
            prev = curr;
        }
    }

    return res;
}

int main() {
    
    vector<pair<int, int>> activities = { // Each pair = {start time, finish time}
        {12, 25},
        {10, 20},
        {20, 30}
    };

    cout << maxActivity(activities) << endl;

    return 0;
}
