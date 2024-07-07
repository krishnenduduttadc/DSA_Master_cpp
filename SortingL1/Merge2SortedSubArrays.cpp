#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted subarrays within array 'a'
vector<int> mergeTwoSortedSubArray(vector<int>& a, int s, int m, int e) {
    vector<int> temp(e - s + 1);
    int p1 = s;
    int p2 = m + 1;
    int p3 = 0;

    // Merge elements from two subarrays into temp array
    while (p1 <= m && p2 <= e) {
        if (a[p1] < a[p2]) {
            temp[p3] = a[p1];
            p3++;
            p1++;
        } else {
            temp[p3] = a[p2];
            p3++;
            p2++;
        }
    }

    // Copy remaining elements of the first subarray, if any
    while (p1 <= m) {
        temp[p3] = a[p1];
        p3++;
        p1++;
    }

    // Copy remaining elements of the second subarray, if any
    while (p2 <= e) {
        temp[p3] = a[p2];
        p3++;
        p2++;
    }

    // Copy sorted elements from temp back to original array 'a'
    for (int i = 0; i < temp.size(); i++) {
        a[s + i] = temp[i];
    }

    return a;
}

int main() {
    // Hard-coded input
    vector<int> A = {1, 3, 5, 7, 2, 4, 6, 8};
    int s = 0;
    int m = 3; // Middle index of the first sorted subarray
    int e = 7; // End index of the second sorted subarray

    // Merging the two sorted subarrays
    vector<int> result = mergeTwoSortedSubArray(A, s, m, e);

    // Print the result
    cout << "Merged array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
