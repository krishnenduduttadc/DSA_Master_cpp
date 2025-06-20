#include <iostream>
#include <algorithm>
using namespace std;


    static int countTriangles(int arr[], int n) {
        sort(arr, arr + n);
        int count = 0;

        for (int i = n - 1; i >= 2; i--) {
            int left = 0, right = i - 1;

            while (left < right) {
                if (arr[left] + arr[right] > arr[i]) {
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
    int n = 5;
    int arr[] = {6, 4, 9, 2, 8};

    int result = countTriangles(arr, n);

    cout << "Number of triangles possible: " << result << endl;

    return 0;
}
