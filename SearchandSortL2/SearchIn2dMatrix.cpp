#include <iostream>
#include <vector>
using namespace std;

bool b(vector<vector<int>>& matrix, int r, int target) {
    int lo = 0;
    int hi = matrix[r].size() - 1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (matrix[r][mid] == target) {
            return true;
        } else if (matrix[r][mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return false;
}

int b1(vector<vector<int>>& matrix, int target) {
    int lo = 0;
    int hi = matrix.size() - 1;
    int lc = matrix[0].size() - 1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (matrix[mid][0] <= target && target <= matrix[mid][lc]) {
            return mid;
        } else if (matrix[mid][0] < target) {
            lo = mid + 1;
        } else if (matrix[mid][0] > target) {
            hi = mid - 1;
        }
    }

    return -1;
}

bool search(vector<vector<int>>& matrix, int target) {
    int row = b1(matrix, target);
    if (row == -1) {
        return false;
    }

    return b(matrix, row, target);
}

int main() {
    int m = 4;
    int n = 4;

    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int target = 13;

    bool isFound = search(matrix, target);
    cout << boolalpha << isFound << endl;

    return 0;
}
