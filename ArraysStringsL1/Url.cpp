#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
void replace(char* str, int trueLength) {
    int spaceCount = 0, index, i = 0;

    // Count the number of spaces in the true part of the string
    for (i = 0; i < trueLength; i++) {
        if (str[i] == ' ') {
            spaceCount++;
        }
    }

    // Calculate the new length of the array after replacements
    index = trueLength + spaceCount * 2;

    // Replace spaces from the end to the beginning
    for (i = trueLength - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index = index - 3;
        } else {
            str[index - 1] = str[i];
            index--;
        }
    }

    // Print the modified string
    cout << str << endl;
}

int main() {
    string s = "Mr John Smith"; // original string without extra spaces
    int trueLength = s.length(); // the true length of the string
    int newLength = trueLength + 3 * 2; // allocate space for additional characters

    char* str = new char[newLength + 1]; // +1 for null terminator
    copy(s.begin(), s.end(), str);
    str[trueLength] = '\0'; // Null-terminate the string

    try {
        replace(str, trueLength);
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    delete[] str; // Free the dynamically allocated memory
    return 0;
}