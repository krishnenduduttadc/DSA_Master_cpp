#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int st = n;
    int sp = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sp; j++){
            cout << "	"; // Print tabs for leading spaces in each row
        }

        for(int j = 1; j <= st; j++){
            if(i > 1 && i <= n / 2 && j > 1 && j < st){
                cout << "	"; // Print tabs for spaces between stars in the upper half of the pattern
            } else {
                cout << "*	"; // Print stars followed by a tab
            }
        }

        if(i <= n / 2){
            sp++; // Increment spaces for upper half
            st -= 2; // Decrease stars for upper half
        } else {
            sp--; // Decrease spaces for lower half
            st += 2; // Increase stars for lower half
        }

        cout << endl; // Move to the next line after each row
    }

    return 0;
}
