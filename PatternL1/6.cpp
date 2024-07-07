#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int sp = 1;
    int str = n / 2 + 1;

    for(int i = 1; i <= n; i++) {
        // Printing stars on the left side
        for(int j = 1; j <= str; j++) {
            cout << "*	"; // printing asterisk and tab character
        }

        // Printing spaces in the middle
        for(int j = 1; j <= sp; j++) {
            cout << "	"; // printing tab character
        }

        // Printing stars on the right side
        for(int j = 1; j <= str; j++) {
            cout << "*	"; // printing asterisk and tab character
        }

        // Adjusting str and sp for the next row
        if(i <= n / 2) {
            str--;
            sp += 2;
        } else {
            str++;
            sp -= 2;
        }

        cout << endl; // moving to next line after each row
    }

    return 0;
}
