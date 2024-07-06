#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int sol(vector<int>& arr) {
    int ans = 0;
    unordered_map<string, int> map;
    int countz = 0, counto = 0, countt = 0;
    int delta10 = counto - countz;
    int delta21 = countt - counto;
    string key = to_string(delta21) + "#" + to_string(delta10);
    map[key] = -1;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            countz++;
        } else if (arr[i] == 1) {
            counto++;
        } else {
            countt++;
        }

        delta10 = counto - countz;
        delta21 = countt - counto;
        key = to_string(delta21) + "#" + to_string(delta10);

        if (map.find(key) != map.end()) {
            int idx = map[key];
            int len = i - idx;
            if (len > ans) {
                ans = len;
            }
        } else {
            map[key] = i;
        }
    }
    
    return ans;
}

int main() {
    vector<int> arr = {1, 1, 2, 0, 1, 0, 1, 2, 1, 2, 2, 0, 1};
    cout << sol(arr) << endl; // Output: 8
    
    return 0;
}
