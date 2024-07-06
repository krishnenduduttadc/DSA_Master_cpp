#include <iostream>
#include <vector>
#include <climits>
using namespace std;

string ans = "";
int mindiff = INT_MAX;

void solve(vector<int>& arr, int vidx, vector<int>& set1, vector<int>& set2, int soset1, int soset2) {
    if (vidx == arr.size()) {
        int delta = abs(soset1 - soset2);
        if (delta < mindiff) {
            mindiff = delta;
            ans = "[ ";
            for (int num : set1) {
                ans += to_string(num) + " ";
            }
            ans += "] [ ";
            for (int num : set2) {
                ans += to_string(num) + " ";
            }
            ans += "]";
        }
        return;
    }

    if (set1.size() < (arr.size() + 1) / 2) {
        set1.push_back(arr[vidx]);
        solve(arr, vidx + 1, set1, set2, soset1 + arr[vidx], soset2);
        set1.pop_back();
    }

    if (set2.size() < (arr.size() + 1) / 2) {
        set2.push_back(arr[vidx]);
        solve(arr, vidx + 1, set1, set2, soset1, soset2 + arr[vidx]);
        set2.pop_back();
    }
}

int main() {
    vector<int> arr = {1, 5, 2, 4};
    vector<int> set1, set2;
    solve(arr, 0, set1, set2, 0, 0);
    cout << ans << endl;
    return 0;
}
