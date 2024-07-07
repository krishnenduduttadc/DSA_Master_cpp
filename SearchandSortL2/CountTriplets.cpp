#include <iostream>
#include <algorithm>
using namespace std;

class CountTheTriplets {
public:
    static int countTriplets(int arr[], int n) {
        // Sort the array
        sort(arr, arr + n);
        int count = 0;

        // Traverse the array from the end to find triplets
        for (int i = n - 1; i >= 2; i--) {
            int left = 0, right = i - 1;

            // Two pointers technique to find triplets
            while (left < right) {
                if (arr[left] + arr[right] == arr[i]) {
                    // If valid triplet is found
                    count++;
                    left++;
                    right--;
                } else if (arr[left] + arr[right] < arr[i]) {
                    // Move left pointer to increase the sum
                    left++;
                } else {
                    // Move right pointer to decrease the sum
                    right--;
                }
            }
        }

        return count;
    }
};

int main() {
    // Hardcoded input
    int n = 6;
    int arr[] = {1, 3, 5, 2, 7, 4};

    // Call the countTriplets method to count triplets
    int result = CountTheTriplets::countTriplets(arr, n);

    // Print the result
    cout << "Number of triplets: " << result << endl;

    return 0;
}
