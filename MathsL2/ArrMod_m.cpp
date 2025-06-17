#include <iostream>
using namespace std;


    static void start() {
        // Hardcoded input array
        int arr[] = {3, 1, 4, 1, 5}; // Example input
        int n = sizeof(arr) / sizeof(arr[0]);
        long long num = 0;
        long long mult = 1;
        int p = 1000000007;

        for (int i = n - 1; i >= 0; i--) {
            num = (num % p + ((arr[i] % p) * (mult % p)) % p) % p;
            mult = (mult * 10) % p;
        }

        cout << num << endl;
    }


int main() {
    start();
    return 0;
}
