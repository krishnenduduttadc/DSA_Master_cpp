#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int sol(const vector<int> arr) {
    int count = 0;
    unordered_map<int, int> map;
    int sum = 0;
    map[0] = 1;

    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];

        if (map.find(sum) != map.end()) {
            count += map[sum];
            map[sum]++;
        } else {
            map[sum] = 1;
        }
    }

    return count;
}

int main() {
    vector<int> arr = {2, 8, -3, -5, 2, -4, 6, 1, 2, 1, -3, 4};
    int result = sol(arr);
    cout << result << endl;
    return 0;
}
