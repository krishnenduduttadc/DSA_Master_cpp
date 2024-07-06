#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<int>& arr, int target) {
    int ans = 0;
    unordered_map<int, int> map;
    map[0] = 1; // Initialize with sum 0 having count 1
    int sum = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (map.find(sum - target) != map.end()) {
            ans += map[sum - target];
        }
        map[sum]++;
    }
    
    return ans;
}

int main() {
    vector<int> arr = {1, 1, 1};
    int target = 2;
    cout << solution(arr, target) << endl; // Output: 2

    return 0;
}
