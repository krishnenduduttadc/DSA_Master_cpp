#include <iostream>

#include <cmath>

using namespace std;


bool isPerfectSquare(int num) {
    int rt = sqrt(num);
    return rt * rt == num;
}

bool judgeSquareSum(long long int c) {
    for (int a = 0; a * a <= c; a++) {
        int b2 = c - a * a;
        if (isPerfectSquare(b2)) {
            return true;
        }
    }
    return false;
}

int main() {
    long long int c;
    cin >> c;

    if (judgeSquareSum(c)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}


/*
25
*/