#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                cout << "*	"; // printing asterisk and tab character
            } else {
                cout << "	"; // printing tab character
            }
        }
        cout << endl; // moving to next line after each row
    }

    return 0;
}
