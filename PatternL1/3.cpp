#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int sp = n - 1, st = 1;

    for (int i = 1; i <= n; i++) {
        // Printing spaces
        for (int j = 1; j <= sp; j++) {
            cout << "	"; // Printing tab character
        }

        // Printing stars
        for (int j = 1; j <= st; j++) {
            cout << "*	"; // Printing asterisk and tab character
        }

        // Adjusting sp and st for the next row
        sp--;
        st++;

        cout << endl; // Moving to next line after each row
    }

    return 0;
}
