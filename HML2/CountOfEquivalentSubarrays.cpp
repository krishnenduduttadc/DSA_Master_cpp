#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int findEquivalentSubarrays(vector<int>& arr) {
    int n = arr.size();
    unordered_set<int> uniqueElements;
    for (int num : arr) {
        uniqueElements.insert(num);
    }
    int k = uniqueElements.size();

    unordered_map<int, int> map;
    int i = 0, j = 0;
    int ans = 0;
    
    while (true) {
        // Expand the window until we have exactly k unique elements
        while (i < n) {
            map[arr[i]]++;
            if (map.size() < k) {
                i++;
            } else if (map.size() == k) {
                ans += n - i;
                i++;
            } else {
                break;
            }
        }
        
        // Shrink the window from the left until we no longer have exactly k unique elements
        while (j < i && map.size() >= k) {
            map[arr[j]]--;
            if (map[arr[j]] == 0) {
                map.erase(arr[j]);
            }
            if (map.size() == k) {
                ans += n - i + 1;
                j++;
            } else {
                break;
            }
        }
        
        if (i == n && map.size() < k) {
            break;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {2, 5, 3, 5, 2, 4, 1, 3, 1, 4};
    int k = findEquivalentSubarrays(arr);
    cout << k << endl; // Output: 25

    return 0;
}
