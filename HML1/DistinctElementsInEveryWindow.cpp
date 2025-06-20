#include <iostream>
#include <unordered_map> // for unordered_map

using namespace std;

void printDistinct(int arr[], int n, int k) {
    unordered_map<int, int> m; // Declaration of unordered_map to store element frequencies

    for (int i = 0; i < k; i++) {
        m[arr[i]]++;
    }

    cout << m.size() << " ";

    for (int i = k; i < n; i++) {
        m[arr[i - k]]--;

        if (m[arr[i - k]] == 0) {
            m.erase(arr[i - k]);
        }

        m[arr[i]]++;

        cout << m.size() << " ";
    }
}

int main() {
    int arr[] = {10, 10, 5, 3, 20, 5};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int k = 4; // Size of the window

    printDistinct(arr, n, k);
    
    cout << endl;

    return 0;
}
