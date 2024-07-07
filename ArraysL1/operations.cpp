#include <iostream>
using namespace std;

int search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;  
}

int insert(int arr[], int& n, int x, int cap, int pos) {
    if (n == cap) return n;

    int idx = pos - 1;
    for (int i = n - 1; i >= idx; i--) {
        arr[i + 1] = arr[i];
    }
    arr[idx] = x;
    return ++n;
}

int deleteElement(int arr[], int& n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            break;
    }

    if (i == n) return n;

    for (int j = i; j < n - 1; j++) {
        arr[j] = arr[j + 1];
    }
    return --n;
}

int main() {
    int arr[] = {5, 7, 6, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << search(arr, n, 4) << endl;

    int cap = 10; // Example capacity
    insert(arr, n, 20, cap, 3); // Example insert operation, uncomment to test
    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    deleteElement(arr, n, 7); // Example delete operation
    cout << "Array after deletion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
