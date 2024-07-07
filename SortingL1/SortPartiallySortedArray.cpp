#include <iostream>
#include <vector>
using namespace std;

class SortPartiallySortedArray {
public:
    static void insertElement(vector<int>& arr) {
        int n = arr.size();
        for (int j = n - 2; j >= 0; j--) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            } else {
                break;
            }
        }
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
    vector<int> arr = {3, 1, 4, 1, 5}; // Example input

    // Calling the insertElement method to process the array
    SortPartiallySortedArray::insertElement(arr);

    // Printing the processed array
    SortPartiallySortedArray::printArray(arr);

    return 0;
}
