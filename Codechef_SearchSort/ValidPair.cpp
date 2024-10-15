#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> pairs(n);
    
    // Input pairs
    for (int i = 0; i < n; ++i) {
        cin >> pairs[i].first >> pairs[i].second;
    }
    
    int left, right;
    cin >> left >> right;
    
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

/*
3
1 2
2 3
4 5
3 15
*/