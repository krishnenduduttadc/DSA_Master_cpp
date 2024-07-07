#include <iostream>
#include <vector>
using namespace std;

class RearrangeArray {
public:
    static void rearrange(vector<int>& arr) {
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
        swap(arr[0], arr[p2]);
    }

    static void printArray(vector<int>& arr) {
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    // Hardcoded input array
    vector<int> arr = {10, 7, 8, 9, 1, 5}; // Example input

    // Calling the rearrange method to process the array
    RearrangeArray::rearrange(arr);

    // Printing the processed array
    RearrangeArray::printArray(arr);

    return 0;
}
