#include <iostream>
#include <vector>
using namespace std;

void insertElement(vector<int>& arr) {
    int n = arr.size();
    for (int j = n - 2; j >= 0; j--) {
        if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
        } else {
            break;
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {3, 1, 4, 1, 5}; // Example input
    insertElement(arr);
    printArray(arr);
    return 0;
}
