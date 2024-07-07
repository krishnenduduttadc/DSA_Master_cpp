#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int sp = n / 2;
    int str = 1;

    for(int i = 1; i <= n; i++) {
        // Printing spaces
        for(int j = 1; j <= sp; j++) {
            cout << "	"; // printing tab character
        }

        // Printing stars
        for(int j = 1; j <= str; j++) {
            cout << "*	"; // printing asterisk and tab character
        }

        // Adjusting sp and str for the next row
        if(i <= n / 2) {
            sp--;
            str += 2;
        } else {
            sp++;
            str -= 2;
        }

        cout << endl; // moving to next line after each row
    }

    return 0;
}
