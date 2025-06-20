#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    unordered_map<int, int> map;
    int ans = 0;
    map[0] = 1; // Initialize with sum 0 having count 1
    int sum = 0;
    
    for (int val : arr) {
        if (val == 0) {
            sum += -1;
        } else {
            sum += 1;
        }
        
        if (map.find(sum) != map.end()) {
            ans += map[sum];
            map[sum]++;
        } else {
            map[sum] = 1;
        }
    }
    
    return ans;
}

int main() {
    vector<int> arr = {0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1};
    cout << solution(arr) << endl; // Output the result

    return 0;
}
