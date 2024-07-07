#include <iostream>
#include <stack>
#include <string>
using namespace std;

void smallestNumberFollowingPattern(string str) {
    stack<int> st;
    int num = 1;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch == 'd') {
            st.push(num);
            num++;
        } else { // ch == 'i'
            st.push(num);
            num++;
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
        }
    }

    // Print remaining elements in the stack
    st.push(num);
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

int main() {
    // Example usage
    string pattern = "ddddiiii";
    smallestNumberFollowingPattern(pattern);

    return 0;
}
