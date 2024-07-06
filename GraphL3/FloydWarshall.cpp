#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FloydWarshall {
public:
    void shortest_distance(vector<vector<int>>& matrix) {
        int n = matrix.size();
        const int INF = 1e9;

        // Initialize the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = INF;
                }
                if (i == j) matrix[i][j] = 0;
            }
        }

        // Floyd-Warshall algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][k] < INF && matrix[k][j] < INF) {
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }

        // Revert the values to -1 where there is no path
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == INF) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};

int main() {
    int V = 4;
    vector<vector<int>> matrix(V, vector<int>(V, -1));

    matrix[0][1] = 2;
    matrix[1][0] = 1;
    matrix[1][2] = 3;
    matrix[3][0] = 3;
    matrix[3][1] = 5;
    matrix[3][2] = 4;

    FloydWarshall obj;
    obj.shortest_distance(matrix);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
