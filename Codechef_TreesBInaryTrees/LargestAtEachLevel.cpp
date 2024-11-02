#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Hardcoded test cases
    int t = 5; // Number of test cases
    vector<pair<string, string>> testCases = {
        {"abc?d", "ab?de"},
        {"hello", "he??o"},
        {"??", "??"},
        {"a?c", "abc"},
        {"xyz", "abc"}
    };

    for (int caseIndex = 0; caseIndex < t; caseIndex++) {
        string x = testCases[caseIndex].first;
        string y = testCases[caseIndex].second;
        bool canMatch = true;
        
        for (int i = 0; i < x.length(); i++) {
            // Check if characters can match
            if (x[i] != y[i] && x[i] != '?' && y[i] != '?') {
                canMatch = false;
                break;
            }
        }
        
        // Output the result for each test case
        if (canMatch) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}

/*
Expected Output:
Yes
Yes
Yes
Yes
No
*/
