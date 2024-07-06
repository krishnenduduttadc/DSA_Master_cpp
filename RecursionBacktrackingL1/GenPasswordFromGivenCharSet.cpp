#include <iostream>
using namespace std;

void generate(char arr[], int i, string s, int len) {
    if (i == 0) {
        cout << s << endl;
        return;
    }
    for (int j = 0; j < len; j++) {
        string app = s + arr[j];
        generate(arr, i - 1, app, len);
    }
}

void crack(char arr[], int len) {
    for (int i = 1; i <= len; i++) {
        generate(arr, i, "", len);
    }
}

int main() {
    char arr[] = {'a', 'b', 'c'};
    int len = sizeof(arr) / sizeof(arr[0]);
    crack(arr, len);
    return 0;
}
