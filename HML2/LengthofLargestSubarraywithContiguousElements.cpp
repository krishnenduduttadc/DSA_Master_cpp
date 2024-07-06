#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int sol(vector<int>& arr) {
    int ans = 0;
    
    for (int i = 0; i < arr.size() - 1; i++) {
        int min_val = arr[i];
        int max_val = arr[i];
        unordered_set<int> contiguous_set;
        contiguous_set.insert(arr[i]);
        
        for (int j = i + 1; j < arr.size(); j++) {
            if (contiguous_set.find(arr[j]) != contiguous_set.end()) {
                break; // If duplicate found, break the loop
            }
            
            contiguous_set.insert(arr[j]);
            min_val = min(min_val, arr[j]);
            max_val = max(max_val, arr[j]);
            
            if (max_val - min_val == j - i) {
                int len = j - i + 1;
                if (len > ans) {
                    ans = len;
                }
            }
        }
    }
    
    return ans;
}

int main() {
    vector<int> arr = {9, 2, 1, 5, 6, 23, 24, 22, 23, 19, 17, 16, 18, 39, 0};
    cout << sol(arr) << endl; // Output: 6
    
    return 0;
}
