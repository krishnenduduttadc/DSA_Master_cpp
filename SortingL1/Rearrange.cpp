#include <iostream>
#include <vector>
using namespace std;

// Function to rearrange the array around the first element as pivot
void rearrange(vector<int>& arr) {
    int n = arr.size();
    int p1 = 1;
    int p2 = n - 1;
    while (p1 <= p2) {
        if (arr[p1] <= arr[0]) {
            p1++;
        } else if (arr[p2] > arr[0]) {
            p2--;
        } else {
            swap(arr[p1], arr[p2]);
            p1++;
            p2--;
        }
    }
    swap(arr[0], arr[p2]); // Place pivot at correct position
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Hardcoded input array
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    // Rearranging the array
    rearrange(arr);

    // Printing the rearranged array
    printArray(arr);

    return 0;
}
