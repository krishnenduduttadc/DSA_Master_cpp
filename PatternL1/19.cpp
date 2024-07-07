#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == 1){
                if(j == n || j <= n / 2 + 1){
                    cout << "*	"; // Print star and tab for specified columns in the first row
                } else {
                    cout << "	"; // Print tab for other spaces in the first row
                }
            } else if(i <= n / 2){
                if(j == n || j == n / 2 + 1){
                    cout << "*	"; // Print star and tab for specified columns in the upper half
                } else {
                    cout << "	"; // Print tab for other spaces in the upper half
                }
            } else if(i == n / 2 + 1){
                cout << "*	"; // Print star and tab for the middle row
            } else if(i < n){
                if(j == 1 || j == n / 2 + 1){
                    cout << "*	"; // Print star and tab for specified columns in the lower half
                } else {
                    cout << "	"; // Print tab for other spaces in the lower half
                }
            } else {
                if(j == 1 || j >= n / 2 + 1){
                    cout << "*	"; // Print star and tab for specified columns in the last row
                } else {
                    cout << '	'; // Print tab for other spaces in the last row
                }
            }
        }
        cout << endl; // Move to the next line after each row
    }

    return 0;
}
