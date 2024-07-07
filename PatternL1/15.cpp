#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int sp = n / 2;
    int st = 1;
    int val = 1;

    for(int i = 1; i <= n; i++){
        // Print spaces before the pattern
        for(int j = 1; j <= sp; j++){
            cout << "	";
        }

        int cval = val;
        // Print the pattern elements
        for(int j = 1; j <= st; j++){
            cout << cval << "	";

            // Update cval based on the position in the row
            if(j <= st / 2){
                cval++;
            } else {
                cval--;
            }
        }

        // Update sp, st, and val for the next row
        if(i <= n / 2 ){
            sp--;
            st += 2;
            val++;
        } else {
            sp++;
            st -= 2;
            val--;
        }

        cout << endl; // Move to the next line after each row
    }

    return 0;
}
