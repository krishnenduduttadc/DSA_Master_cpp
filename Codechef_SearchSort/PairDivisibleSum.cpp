#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 3; // Hardcoded number of pairs
    int k = 5; // Hardcoded value of k
    
    vector<pair<int, int>> pairs(n);
    
    pairs[0] = {1, 4}; // Hardcoded values for the first pair
    pairs[1] = {2, 5}; // Hardcoded values for the second pair
    pairs[2] = {6, 4}; // Hardcoded values for the third pair
    
    for (int i = 0; i < n; ++i) {
        if ((pairs[i].first + pairs[i].second) % k == 0) {
            cout << "(" << pairs[i].first << ", " << pairs[i].second << ")" << endl;
        }
    }
    
    return 0;
}
