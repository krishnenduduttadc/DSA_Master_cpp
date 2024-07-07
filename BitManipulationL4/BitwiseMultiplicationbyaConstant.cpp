#include <iostream>
using namespace std;

int main() {
    int num = 5;
    int constant = 3;
    int result = (num << 1) + num; // Multiply by 3 using bit manipulation
    cout << "Result: " << result << endl; // Output: 15
    
    return 0;
}
