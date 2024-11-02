#include <bits/stdc++.h>
using namespace std;

// Function to return the intersection of two ranges
pair<int, int> intersect(pair<int, int> a, pair<int, int> b) {
    return {max(a.first, b.first), min(a.second, b.second)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // Hardcoded test cases
    int t = 1; // Number of test cases

    while (t--) {
        int n = 4; // Number of ranges
        vector<pair<int, int>> ranges = {
            {2, 2},
            {1, 1},
            {1, 3},
            {1, 3}
        };

        vector<pair<int, int>> prefix(n), suffix(n);
        
        // Compute prefix intersections
        prefix[0] = ranges[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = intersect(prefix[i - 1], ranges[i]);
        }

        // Compute suffix intersections
        suffix[n - 1] = ranges[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = intersect(suffix[i + 1], ranges[i]);
        }

        vector<int> possible_thieves;
        
        for (int i = 0; i < n; i++) {
            // Calculate intersection excluding the current person
            pair<int, int> current_intersection = {1, n};
            if (i > 0) {
                current_intersection = intersect(current_intersection, prefix[i - 1]);
            }
            if (i < n - 1) {
                current_intersection = intersect(current_intersection, suffix[i + 1]);
            }
            
            // Check if person i could be the thief
            if (i + 1 >= current_intersection.first && i + 1 <= current_intersection.second
                && (i + 1 < ranges[i].first || i + 1 > ranges[i].second)) {
                possible_thieves.push_back(i + 1);
            }
        }

        // Output the number of possible thieves and their indices
        cout << possible_thieves.size() << '\n';
        for (int thief : possible_thieves) {
            cout << thief << '\n';
        }
    }

    return 0;
}
