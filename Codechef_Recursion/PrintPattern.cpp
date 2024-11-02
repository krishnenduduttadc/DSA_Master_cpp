#include <iostream>
using namespace std;

void print_pattern(int n) {
    if (n == 0) {
        return; // Base case: if n is 0, return without printing
    }
    for (int i = 0; i < n; ++i) {
        cout << "*"; // Print n asterisks
    }
    cout << endl; // Move to the next line
    print_pattern(n - 1); // Recursive call with n-1
}

int main() {
    // Hardcoded input value
    int n = 4; // You can change this value to test with different inputs
    print_pattern(n); // Call the function to print the pattern
    return 0;
}
