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
    return left; // 'left' is the count of elements <= x
}

// Function to find the median in the matrix
int findMedian(vector<vector<int>>& matrix, int N, int M) {
    int left = 0;  // Start with the smallest possible value based on constraints
    int right = 1000; // Start with the largest possible value based on constraints
    int desiredCount = (N * M) / 2; // Mid index for odd total elements

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int count = 0;
        for (int i = 0; i < N; i++) {
            count += countLessEqual(matrix[i], mid);
        }

        // If count is less than or equal to desiredCount, we need to search in the right half
        if (count <= desiredCount) {
            left = mid + 1; // Move right
        } else {
            right = mid - 1; // Move left
        }
    }

    // left is the median value at this point
    return left;
}

int main() {
    int N, M;
    cin >> N >> M; // Read dimensions of the matrix

    vector<vector<int>> matrix(N, vector<int>(M)); // Initialize the matrix

    // Read the matrix elements
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    // Find and print the median
    cout << findMedian(matrix, N, M) << endl;

    return 0;
}


/*
3 3
3 4 5
2 4 6
4 6 7

*/