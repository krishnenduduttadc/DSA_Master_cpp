#include <iostream>
#include <vector>

using namespace std;

bool pairWithGivenSum(const vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        if (arr[left] + arr[right] == x) {
            return true;
        } else if (arr[left] + arr[right] > x) {
            right--;
        } else {
            left++;
        }
    }
    return false;
}

int main() {
    vector<int> arr = {10, 7, 8, 20, 12};
    int x = 32;

    cout << std::boolalpha << pairWithGivenSum(arr, x) << endl;
    return 0;
}
