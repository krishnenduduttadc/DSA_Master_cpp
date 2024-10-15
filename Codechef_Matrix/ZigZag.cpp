#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // read dimensions of the matrix

    int arr[n][m];
    for (int i = 0; i < n; i++) { // loop through rows
        for (int j = 0; j < m; j++) { // loop through columns
            cin >> arr[i][j]; // read each element
        }
    }

    bool dirl = true;
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            if (dirl == true) {
                cout << arr[i][j] << " ";
            }
            else if (dirl == false) {
                cout << arr[i][m - j - 1] << " ";
            }

        }
        dirl = !dirl;
    }

}

/*
3 3
4 6 0
8 2 1
3 1 5

*/