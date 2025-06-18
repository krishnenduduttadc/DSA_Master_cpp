#include <iostream>
#include <cmath>
using namespace std;

int convertStringToInt(string input) {
    if (input.length() == 1) {
        return (input[0] - '0');
    }

    double y = convertStringToInt(input.substr(1));
    double x = input[0] - '0';
    x = x * pow(10, input.length() - 1) + y;
    return static_cast<int>(x);
}

int main() {
    string input;
    cout << "Enter a number as string: ";
    cin >> input;

    int result = convertStringToInt(input);

    cout << "Converted integer: " << result << endl;

    return 0;
}
