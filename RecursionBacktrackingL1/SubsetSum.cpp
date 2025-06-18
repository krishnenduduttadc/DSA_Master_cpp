#include <iostream>
using namespace std;

void subsetSums(int arr[], int l, int r, int sum) {
    if (l > r) {
        cout << sum << " ";
        return;
    }
    
    subsetSums(arr, l + 1, r, sum + arr[l]);
}

int main() {
    int arr[] = {5, 4, 3, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    subsetSums(arr, 0, n - 1, 0);
    
    return 0;
}
