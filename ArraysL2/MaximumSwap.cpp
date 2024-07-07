#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

string maximumSwap(string num) {
    vector<int> last_occurrence(10, -1); // Store last occurrence index of each digit 0-9
    
    // Record the last occurrence index of each digit in the number
    for (int i = 0; i < num.size(); ++i) {
        last_occurrence[num[i] - '0'] = i;
    }
    
    // Traverse the number to find the first position where a swap would increase the number
    for (int i = 0; i < num.size(); ++i) {
        for (int j = 9; j > num[i] - '0'; --j) {
            if (last_occurrence[j] > i) { // Found a larger digit that appears later in the number
                swap(num[i], num[last_occurrence[j]]);
                return num; // Return the modified number after one swap
            }
        }
    }
    
    return num; // If no swap can increase the number, return the original number
}

int main() {
    string num = "2736";
    string result = maximumSwap(num);
    cout << result << endl;
    
    return 0;
}
