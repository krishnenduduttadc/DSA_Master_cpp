#include <iostream>
#include <string>
using namespace std;

void searchPattern(const string& text, const string& pat) {
    int m = pat.length();
    int n = text.length();

    for (int i = 0; i <= n - m; ++i) {
        int j;
        for (j = 0; j < m; ++j) {
            if (text[i + j] != pat[j]) {
                break;
            }
        }
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string text = "ababaababbbbabaaa";
    string pat = "aa";

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pat << endl;

    searchPattern(text, pat);

    return 0;
}
