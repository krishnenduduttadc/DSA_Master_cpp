#include <iostream>
#include <vector>

using namespace std;

int countOnes(const vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == 0) {
            low = mid + 1;
        } else {
            if (mid == 0 || arr[mid - 1] == 0) {
                return arr.size() - mid;
            } else {
                high = mid - 1;
            }
        }
    }
    return 0;
}

int main() {
    vector<int> arr = {0, 0, 0, 1, 1, 1, 1, 1};
    cout << countOnes(arr) << endl;
    return 0;
}
