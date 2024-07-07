#include <iostream>
#include <stack>
using namespace std;

void findCelebrity(int arr[][4], int n) {
    stack<int> st;
    for (int i = 0; i < n; i++) {
        st.push(i);
    }

    while (st.size() > 1) {
        int i = st.top();
        st.pop();
        int j = st.top();
        st.pop();

        if (arr[i][j] == 1) {
            st.push(j);
        } else {
            st.push(i);
        }
    }

    int potential = st.top();
    bool isCelebrity = true;
    for (int i = 0; i < n; i++) {
        if (i != potential) {
            if (arr[i][potential] == 0 || arr[potential][i] == 1) {
                isCelebrity = false;
                break;
            }
        }
    }

    if (isCelebrity) {
        cout << potential << endl;
    } else {
        cout << "none" << endl;
    }
}

int main() {
    // Hardcoded input
    int n = 4;
    int arr[4][4] = {
        {0, 0, 0, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };

    // Finding the celebrity
    findCelebrity(arr, n);

    return 0;
}
