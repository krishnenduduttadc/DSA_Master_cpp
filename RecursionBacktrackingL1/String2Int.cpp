#include <iostream>
#include <cmath>
using namespace std;

// Function to convert string to integer recursively
int convertStringToInt(string input) {
    // Base case: if the input string has only one character
    if (input.length() == 1) {
        return (input[0] - '0');
    }

    // Recursive case: convert substring starting from index 1 to integer
    double y = convertStringToInt(input.substr(1));
    double x = input[0] - '0';
    x = x * pow(10, input.length() - 1) + y;
    return static_cast<int>(x);
}

int main() {
    // Input string
    string input;
    cout << "Enter a number as string: ";
    cin >> input;

    // Convert string to integer using the function
    int result = convertStringToInt(input);

    // Output the result
    cout << "Converted integer: " << result << endl;

    return 0;
}
