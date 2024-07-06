#include <iostream>
using namespace std;

// Function to find sum of elements in array A of size N recursively
int findSum(int A[], int N) {
    // Base case: if N is 0 or less, return 0 (no elements to sum)
    if (N <= 0) {
        return 0;
    }
    // Recursive case: sum of elements up to index N-1 plus A[N-1]
    return findSum(A, N - 1) + A[N - 1];
}

int main() {
    // Define the array as static as in the Java code
    static int arr[] = { 1, 2, 3, 4, 5 };
    // Calculate the sum of elements in the array and print the result
    cout << findSum(arr, sizeof(arr) / sizeof(arr[0])) << endl;
    return 0;
}
