#include <iostream>
using namespace std;

int minJumps(int x) {
    int jump = 1;
    int sum = 0;

    // Find the smallest jump count that reaches or exceeds x
    while (sum < x) {
        sum += jump;
        jump++;
    }

    // Determine the exact number of jumps needed
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
