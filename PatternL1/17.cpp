#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int sp = n / 2;
    int st = 1;

    for(int i = 1; i <= n; i++){
        // Printing spaces before stars
        for(int j = 1; j <= sp; j++){
            cout << "	"; // Using tab for space
        }

        // Printing stars
        for(int j = 1; j <= st; j++){
            cout << "*	"; // Printing star and tab
        }

        // Adjusting spaces and stars for next row
        if(i <= n / 2){
            sp--; // Decrease spaces and increase stars for upper half
            st += 2;
        } else {
            sp++; // Increase spaces and decrease stars for lower half
            st -= 2;
        }

        cout << endl; // Move to the next line
    }

    return 0;
}
