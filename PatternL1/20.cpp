#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j == 1 || j == n){
                cout << "*	"; // Print star and tab for first and last columns
            } else if(i > n / 2 && (i == j || i + j == n + 1)){
                cout << "*	"; // Print star and tab for diagonals in the second half
            } else {
                cout << "	"; // Print tab for other spaces
            }
        }
        cout << endl; // Move to the next line after each row
    }

    return 0;
}
