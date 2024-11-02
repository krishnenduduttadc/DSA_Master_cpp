#include <iostream>
#include <vector>
using namespace std;

void nextGreaterElements(const vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[i]) {
                nge[i] = arr[j];
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << nge[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 4; // Hardcoded size of the array
    vector<int> arr = {4, 5, 2, 10}; // Hardcoded values for the array

    nextGreaterElements(arr);

    return 0;
}
