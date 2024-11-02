#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Hardcoded number of pairs
    int n = 3;  
    
    // Hardcoded pairs
    vector<pair<int, int>> pairs = {
        {1, 2},
        {2, 3},
        {4, 5}
    };
    
    // Hardcoded range values
    int left = 3, right = 15;
    
    // Output pairs whose sum and product are within [left, right]
    for (int i = 0; i < n; ++i) {
        int sum = pairs[i].first + pairs[i].second;
        int product = pairs[i].first * pairs[i].second;
        
        if (sum >= left && sum <= right && product >= left && product <= right) {
            cout << pairs[i].first << " " << pairs[i].second  << endl;
        }
    }
    
    return 0;
}
