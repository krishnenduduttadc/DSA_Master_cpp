#include <iostream>
using namespace std;

int cnt = 0;

int countZerosRec(int input) {
    if (input == 0 && cnt == 0) {
        return 1;
    }
    
    if (input == 0) {
        return cnt;
    }

    if (input % 10 == 0) {
        cnt++;
    }

    return countZerosRec(input / 10);
}

int main() {
    cout << countZerosRec(10034) << endl;
    return 0;
}
