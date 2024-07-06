#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int largestSubarrayWithZeroSum(vector<int>& arr) {
    unordered_map<int, int> hm; // Maps sum to index
    int sum = 0;
    int max_len = 0;
    
    hm[0] = -1; // Initialize to handle the case where sum becomes 0 at the start
    
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        
        if (hm.find(sum) != hm.end()) {
            int len = i - hm[sum];
            if (len > max_len) {
                max_len = len;
            }
        } else {
            hm[sum] = i;
        }
    }
    
    return max_len;
}

int main() {
    vector<int> arr = {2, 8, -3, -5, 2, -4, 6, 1, 2, 1, -3, 4};
    int max_length = largestSubarrayWithZeroSum(arr);
    cout << max_length << endl; // Output: 5
    
    return 0;
}
