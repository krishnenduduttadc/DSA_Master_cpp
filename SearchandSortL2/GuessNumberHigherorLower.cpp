#include <iostream>
using namespace std;

int pn = 0;

int guess(int val) {
    if (val == pn) {
        return 0;
    }
    else if (val < pn) {
        return 1; // Number picked is higher
    }
    else {
        return -1; // Number picked is lower
    }
}

int guessNumber(int n) {
    int lo = 1;
    int hi = n;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        int result = guess(mid);
        if (result == 0) {
            return mid; // Found the correct number
        } else if (result == -1) {
            hi = mid - 1; // Number picked is lower, search in the left half
        } else if (result == 1) {
            lo = mid + 1; // Number picked is higher, search in the right half
        }
    }

    return -1; // Not found (should not reach here as per problem statement)
}

void solve(int n, int pick) {
    pn = pick; // Set the global picked number
    cout << guessNumber(n) << endl;
}

int main() {
    int n = 1000; // Range of numbers to guess from
    int pick = 98; // Picked number to guess

    solve(n, pick);

    return 0;
}
