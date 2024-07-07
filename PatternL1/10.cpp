#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int nos = n / 2;
    int nis = -1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= nos; j++){
            cout << "	"; // printing tab character
        }
        cout << "*	"; // printing asterisk and tab character

        for(int j = 1; j <= nis; j++){
            cout << "	"; // printing tab character
        }

        if(i > 1 && i < n){
            cout << "*	"; // printing asterisk and tab character
        }

        if(i <= n / 2){
            nos--;
            nis += 2;
        } else {
            nos++;
            nis -= 2;
        }

        cout << endl; // moving to next line after each row
    }

    return 0;
}
