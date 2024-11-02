#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 2, c = 7;  // Hardcoded input values
    
    // Sort the integers using simple comparisons and swaps
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    
    cout << a << " " << b << " " << c << endl;  // Output the sorted integers
    return 0;
}
