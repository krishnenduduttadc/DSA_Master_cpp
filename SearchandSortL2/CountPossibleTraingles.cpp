#include <iostream>
#include <algorithm>
using namespace std;


    static int countTriangles(int arr[], int n) {
        // Sort the array
        sort(arr, arr + n);
        int count = 0;

        // Traverse the array from the end to find triangles
        for (int i = n - 1; i >= 2; i--) {
            int left = 0, right = i - 1;

            // Two pointers technique to find valid triangles
            while (left < right) {
                if (arr[left] + arr[right] > arr[i]) {
                    // If valid triangle, all triangles from left to right-1 are also valid
                    count += (right - left);
                    right--;
                } else {
                    left++;
                }
            }
        }

        return count;
    }


int main() {
    // Hardcoded input
    int n = 5;
    int arr[] = {6, 4, 9, 2, 8};

    // Call the countTriangles method to count possible triangles
    int result = countTriangles(arr, n);

    // Print the result
    cout << "Number of triangles possible: " << result << endl;

    return 0;
}
