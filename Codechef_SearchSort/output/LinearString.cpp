#include <bits/stdc++.h>
using namespace std;

int main() {
    string inputString;
    char searchChar;

    // Read the input string
    cin >> inputString;
    
    // Read the character to search for
    cin >> searchChar;

    // Initialize a variable to store the position of the character
    int position = -1;

    // Use a for loop to search for the character in the string
    for (int i = 0; i < inputString.length(); ++i) {
        if (inputString[i] == searchChar) {
            position = i;
            break;
        }
    }

    // Print the result
    if (position != -1) {
        cout << position << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}

/*
HelloHowYouDoing
w
*/