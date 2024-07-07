#include <iostream>
using namespace std;

int sumOfAllSubmatrices(int arr[][3], int n, int m) {
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int occ = (i + 1) * (j + 1) * (n - i) * (m - j);
            ans = ans + (occ * arr[i][j]);
        }
    }

    return ans;
}

int main() {
    int arr[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = sizeof(arr) / sizeof(arr[0]); // Number of rows
    int m = sizeof(arr[0]) / sizeof(arr[0][0]); // Number of columns

    int result = sumOfAllSubmatrices(arr, n, m);

    cout << result << endl;

    return 0;
}
