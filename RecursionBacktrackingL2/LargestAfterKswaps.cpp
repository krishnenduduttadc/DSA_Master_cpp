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
            if (str[j] > str[i]) {
                swap(str[i], str[j]);
                if (str > max_str) {
                    max_str = str;
                }

                findMaximum(str, k - 1);

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
