#include <iostream>
using namespace std;

string max_str;

void findMaximum(string str, int k) {
    if (k == 0) {
        return;
    }

    int n = str.length();

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // If digit at position j is greater than digit at position i, swap them
            if (str[j] > str[i]) {
                swap(str[i], str[j]);

                // Check if current string is larger than previously found max
                if (str > max_str) {
                    max_str = str;
                }

                // Recur for k-1 swaps on the modified string
                findMaximum(str, k - 1);

                // Backtrack: Swap again to revert to original string
                swap(str[i], str[j]);
            }
        }
    }
}

int main() {
    string str = "1234567";
    int k = 4; 
    max_str = str;
    findMaximum(str, k);
    cout << max_str << endl;

    return 0;
}
