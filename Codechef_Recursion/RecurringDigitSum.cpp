#include <iostream>
using namespace std;

int recurrent_sum_of_digits(int n) {
    if (n < 10) 
        return n;
    
    int sum = 0;
    while (n > 0) {
        sum += n % 10; // Add the last digit to sum
        n /= 10; // Remove the last digit
    }
    
    return recurrent_sum_of_digits(sum); // Recursively call the function with the sum
}

int main() {
    // Hardcoded input
    int n = 38; // Example input

    cout << recurrent_sum_of_digits(n) << endl; // Output the result
    return 0;
}
