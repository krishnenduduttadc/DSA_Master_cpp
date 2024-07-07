#include <iostream>
#include <vector>
using namespace std;

class CountZerosInASortedMatrix {
public:
    static int countZeros(vector<vector<int>>& mat) {
        int n = mat.size();
        int i = 0;
        int j = n - 1;
        int countZeros = 0;

        while (i < n && j >= 0) {
            if (mat[i][j] == 1) {
                j--;
            } else {
                countZeros += j + 1;
                i++;
            }
        }

        return countZeros;
    }
};

int main() {
    // Hardcoded input
    int n = 5;
    vector<vector<int>> mat = {
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {0, 1, 1, 1, 1}
    };

    // Call the countZeros method to count zeros
    int result = CountZerosInASortedMatrix::countZeros(mat);

    // Print the result
    cout << "Number of zeros in the sorted matrix: " << result << endl;

    return 0;
}
