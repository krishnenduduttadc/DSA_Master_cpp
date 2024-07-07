#include <iostream>
#include <vector>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int max_val = 0;
    int count = 0;

    for (int i = 0; i < arr.size(); i++) {
        max_val = max(max_val, arr[i]);

        if (i == max_val) {
            count++;
        }
    }

    return count;
}

int main() {
    vector<int> arr = {4, 3, 2, 1, 0};
    int res = maxChunksToSorted(arr);
    cout << res << endl;

    return 0;
}
