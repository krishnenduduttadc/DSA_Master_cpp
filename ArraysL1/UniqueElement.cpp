#include <iostream>
#include <unordered_map>
using namespace std;

int findUnique(int arr[], int n) {
    unordered_map<int, int> hm;
    for (int i = 0; i < n; i++) {
        int key = arr[i];
        hm[key]++;
    }

    for (auto itr : hm) {
        if (itr.second == 1) {
            return itr.first;
        }
    }
    return -1;  // In case no unique element is found
}

int main() {
    int arr[] = {1, 3, 1, 3, 6, 6, 7, 10, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findUnique(arr, n) << endl;
    return 0;
}
