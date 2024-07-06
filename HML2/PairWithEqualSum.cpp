#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool sol(vector<int>& arr) {
    unordered_set<int> set;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            int sum = arr[i] + arr[j];
            if (set.count(sum)) {
                return true;
            } else {
                set.insert(sum);
            }
        }
    }
    return false;
}

int main() {
    vector<int> arr = {2, 9, 3, 5, 8, 6, 4};
    bool ans = sol(arr);
    cout << boolalpha << ans << endl;
    return 0;
}
