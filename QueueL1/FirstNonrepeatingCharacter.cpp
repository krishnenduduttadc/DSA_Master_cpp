#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class FirstNonRepeatingCharacter {
public:
    string FirstNonRepeating(string A) {
        queue<char> q;
        unordered_map<char, int> hm;
        string ans(A.length(), '#');

        for (int i = 0; i < A.length(); i++) {
            char c = A[i];

            q.push(c);
            hm[c]++;

            while (!q.empty() && hm[q.front()] > 1) {
                q.pop();
            }

            if (!q.empty()) {
                ans[i] = q.front();
            }
        }

        return ans;
    }
};

int main() {
    // Hardcoded input string
    string A = "aabc";

    // Create an instance of the FirstNonRepeatingCharacter class
    FirstNonRepeatingCharacter solution;

    // Call the FirstNonRepeating method and store the result
    string result = solution.FirstNonRepeating(A);

    // Print the result
    cout << result << endl;

    return 0;
}
