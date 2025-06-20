#include <iostream>
using namespace std;

int find(int arr[], int n) {
    int maxRooftops = 0;
    int currentCount = 0;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            currentCount++;
        } else {
            if (currentCount > maxRooftops) {
                maxRooftops = currentCount;
            }
            currentCount = 0;
        }
    }

    if (currentCount > maxRooftops) {
        maxRooftops = currentCount;
    }

    return maxRooftops;
}

int main() {
    int arr[] = {1, 4, 5, 7, 6, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxRooftops = find(arr, n);
    cout << "Maximum number of consecutive rooftops: " << maxRooftops << endl;

    return 0;
}
