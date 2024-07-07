#include <iostream>
#include <vector>
using namespace std;

class FindMinimuminRotatedSortedArray {
public:
    static int findMinimum(vector<int>& arr) {
        int lo = 0;
        int hi = arr.size() - 1;

        // If the array is already sorted or has only one element
        if (arr[lo] <= arr[hi]) {
            return arr[0];
        }

        while (lo <= hi) {
            // If the current segment is sorted, the minimum is at lo
            if (arr[lo] <= arr[hi]) {
                return arr[lo];
            }

            int mid = lo + (hi - lo) / 2;
            int next = (mid + 1) % arr.size(); // Calculate next index considering wrap around

            // Check if mid is the minimum element
            if (arr[mid] <= arr[next] && arr[mid] <= arr[mid - 1]) {
                return arr[mid];
            }
            // If the right half is sorted, the minimum is in the left half
            else if (arr[mid] <= arr[hi]) {
                hi = mid - 1;
            }
            // If the left half is sorted, the minimum is in the right half
            else if (arr[lo] <= arr[mid]) {
                lo = mid + 1;
            }
        }

        return -1; // This line should never be reached if the input is valid
    }
};

int main() {
    // Hardcoded input
    vector<int> arr = {4, 5, 6, 7, 8, 0, 1, 3};

    // Call the findMinimum function to find the minimum element
    int ans = FindMinimuminRotatedSortedArray::findMinimum(arr);

    // Print the minimum element
    cout << "Minimum element: " << ans << endl;

    return 0;
}
