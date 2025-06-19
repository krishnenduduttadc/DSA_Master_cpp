#include <iostream>
using namespace std;

int minJumps(int x) {
    int jump = 1;
    int sum = 0;

    while (sum < x) {
        sum += jump;
        jump++;
    }

    if ((sum - x) % 2 == 0) {
        return jump - 1;
    } else if ((sum + jump - x) % 2 == 0) {
        return jump;
    } else {
        return jump + 1;
    }
}

int main() {
    int x = 8;
    int jumps = minJumps(x);
    cout << jumps << endl;
    return 0;
}
