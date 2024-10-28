#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 3;
    vector<vector<int>> inputs = {
        {100, 100, 100},
        {2, 1, 3},
        {30, 1, 30, 30}
    };

    for (int k = 0; k < t; k++) {
        int n = inputs[k].size();
        vector<int> v = inputs[k];
        
        sort(v.begin(), v.end());
        
        int boast_count = 0;
        for (int i = 0; i < n; i++) {
            int count_less_equal = upper_bound(v.begin(), v.end(), v[i]) - v.begin();
            int count_greater = n - count_less_equal;
            
            if (count_less_equal > count_greater)
                boast_count++;
        }
        
        cout << boast_count << '\n';
    }
    return 0;
}
