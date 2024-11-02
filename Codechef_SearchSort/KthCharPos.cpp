#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "HelloHowyoudoing"; // Hardcoded string
    char c1 = 'H';                  // Hardcoded character
    int k = 2;                      // Hardcoded occurrence number

    int count = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == c1) {
            count++;
            if (count == k) {
                cout << i << endl; // Output the index of the k-th occurrence
                return 0;
            }
        }
    }
    
    cout << -1 << endl; // Output -1 if the k-th occurrence is not found
    return 0;
}
