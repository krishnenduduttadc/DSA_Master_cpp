#include <iostream>
using namespace std;

// Global variable to simulate the picked number
int pn = 0;

// Function to guess the number
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

// Function to guess the number using binary search
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

// Utility function to test and print the result
void solve(int n, int pick) {
    pn = pick; // Set the global picked number
    cout << guessNumber(n) << endl;
}

int main() {
    // Hardcoded input
    int n = 1000; // Range of numbers to guess from
    int pick = 98; // Picked number to guess

    // Call the solve function to find and print the guessed number
    solve(n, pick);

    return 0;
}
