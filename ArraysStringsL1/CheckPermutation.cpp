#include <iostream>
#include <algorithm> // for std::sort
#include <string>
using namespace std;

bool permutation(string a, string b) {
    if (a.length() != b.length()) {
        return false;
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    return a == b;
}

int main() {
    string a = "god";
    string b = "dog";
    
    if (permutation(a, b)) {
        cout << "Strings are permutations of each other." << endl;
    } else {
        cout << "Strings are not permutations of each other." << endl;
    }
    
    return 0;
}
