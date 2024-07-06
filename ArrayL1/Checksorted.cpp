#include <iostream>
using namespace std;

bool isSortedEff(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

bool isSorted(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int arr2[] = {11, 2, 3, 4, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << boolalpha; // Print boolean values as true/false
    cout << isSortedEff(arr1, n1) << endl;
    cout << isSortedEff(arr2, n2) << endl;

    cout << isSorted(arr1, n1) << endl;
    cout << isSorted(arr2, n2) << endl;

    return 0;
}
