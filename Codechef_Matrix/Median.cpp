#include <iostream>
#include <vector>
using namespace std;

// Function to count elements less than or equal to x in a row using binary search
int countLessEqual(vector<int>& row, int x) {
    int left = 0, right = row.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (row[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

// Function to find the median in the matrix
int findMedian(vector<vector<int>>& matrix, int N, int M) {
    int left = 0;
    int right = 1000;
    int desiredCount = (N * M) / 2;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int count = 0;
        for (int i = 0; i < N; i++) {
            count += countLessEqual(matrix[i], mid);
        }

        if (count <= desiredCount) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

int main() {
    int N = 3, M = 3;

    vector<vector<int>> matrix = {
        {3, 4, 5},
        {2, 4, 6},
        {4, 6, 7}
    };

    cout << findMedian(matrix, N, M) << endl;

    return 0;
}
