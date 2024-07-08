#include <iostream>
#include <vector>
using namespace std;

void solution(vector<int>& arr) {
    int xor_val = 0;
    int n = arr.size();

    // XOR all elements in arr and numbers from 1 to n
    for (int i = 0; i < n; i++) {
        xor_val ^= arr[i];
        xor_val ^= (i + 1);
    }

    // Find the rightmost set bit
    int rsb = xor_val & -xor_val;

    int x = 0, y = 0;

    // Divide elements into two groups based on rsb
    for (int i = 0; i < n; i++) {
        if (arr[i] & rsb)
            x ^= arr[i];
        else
            y ^= arr[i];
        
        if ((i + 1) & rsb)
            x ^= (i + 1);
        else
            y ^= (i + 1);
    }

    // Check which one is repeating and which one is missing
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            cout << "Missing Number -> " << y << endl;
            cout << "Repeating Number -> " << x << endl;
            break;
        } else if (arr[i] == y) {
            cout << "Missing Number -> " << x << endl;
            cout << "Repeating Number -> " << y << endl;
            break;
        }
    }
}

int main() {
    vector<int> arr = {1, 3, 4, 4, 5, 6, 7};
    solution(arr);
    return 0;
}
