#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void sol(const vector<int> arr, int k) {
    unordered_map<int, int> remainderFreqMap;
    
    for (int val : arr) {
        int rem = val % k;
        remainderFreqMap[rem]++;
    }
    
    for (int val : arr) {
        int rem = val % k;

        if (rem == 0) {
            if (remainderFreqMap[rem] % 2 != 0) {
                cout << "false" << endl;
                return;
            }
        } else if (2 * rem == k) {
            if (remainderFreqMap[rem] % 2 != 0) {
                cout << "false" << endl;
                return;
            }
        } else {
            if (remainderFreqMap[rem] != remainderFreqMap[k - rem]) {
                cout << "false" << endl;
                return;
            }
        }
    }
    
    cout << "true" << endl;
}

int main() {
    vector<int> arr = {22, 12, 45, 55, 65, 78, 88, 75};
    int k = 7;
    sol(arr, k);
    return 0;
}
