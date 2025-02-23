#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int lo = 0, hi = n * m - 1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int r = mid / m;
        int c = mid % m;

        if (matrix[r][c] == target) {
            return true;
        } else if (matrix[r][c] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> matrix1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target1 = 3;

    cout << "Matrix 1 contains target 3: " << boolalpha << searchMatrix(matrix1, target1) << endl; // Output: true

    return 0;
}
