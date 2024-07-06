#include <iostream>
#include <vector>
#include <unordered_map>

class SubarraySumEqualsK {
public:
    static int sol(const std::vector<int>& arr, int target) {
        int ans = 0;
        std::unordered_map<int, int> map;
        map[0] = 1;
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            int rsum = sum - target;
            if (map.find(rsum) != map.end()) {
                ans += map[rsum];
            }
            map[sum]++;
        }
        return ans;
    }
};

int main() {
    std::vector<int> arr = {3, 9, -2, 4, 1, -7, 2, 6, -5, 8, -3, -7, 6, 2, 1};
    int k = 5;
    std::cout << SubarraySumEqualsK::sol(arr, k) << std::endl;
    return 0;
}