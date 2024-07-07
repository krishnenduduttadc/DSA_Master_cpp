#include <iostream>
#include <vector>

using namespace std;

int binsearch(const vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {3, 5, 7, 8, 9};
    cout << binsearch(arr, 8) << endl;
    return 0;
}
