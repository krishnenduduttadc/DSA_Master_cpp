#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int sp = 2 * n - 3;
    int st = 1;

    for(int i = 1; i <= n; i++){
        int val = 1;

        // Print the left part of the pattern
        for(int j = 1; j <= st; j++){
            cout << val << "	";
            val++;
        }

        // Print spaces in the middle part
        for(int j = 1; j <= sp; j++){
            cout << "	";
        }

        // Print the right part of the pattern
        if(i == n){
            st--; // Decrease the number of elements in the last row
            val--; // Adjust the starting value for the right part
        }

        for(int j = 1; j <= st; j++){
            val--;
            cout << val << "	";
        }

        // Adjust st and sp for the next row
        st++;
        sp -= 2;

        cout << endl; // Move to the next line after each row
    }

    return 0;
}
