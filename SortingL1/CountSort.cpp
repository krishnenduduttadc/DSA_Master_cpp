#include <iostream>
#include <cstring>
using namespace std;

string countSort(string s) {
    char arr[s.length()];
    strcpy(arr, s.c_str());

    char maxch = 'a';
    for (int i = 0; i < strlen(arr); i++) {
        if (arr[i] > maxch) {
            maxch = arr[i];
        }
    }
    int max = maxch - 'a';
    int count[max + 1] = {0};

    for (int i = 0; i < strlen(arr); i++) {
        int val = arr[i] - 'a';
        count[val]++;
    }

    int k = 0;
    for (int i = 0; i <= max; i++) {
        int c = count[i];
        for (int j = 0; j < c; j++) {
            arr[k] = i + 'a';
            k++;
        }
    }

    string sortedString(arr);
    return sortedString;
}

int main() {
    string input = "countingsortexample";

    string sortedString = countSort(input);

    cout << "Original String: " << input << endl;
    cout << "Sorted String: " << sortedString << endl;

    return 0;
}
