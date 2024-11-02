#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::pair<int, std::vector<int>>> test_cases = {
        {6, {5, 10, 3, 2, 50, 80}},
        {2, {-10, 20}},
        {4, {1, 2, 3, 4}}
    };
    std::vector<int> B_values = {78, 30, 5};

    for (int t = 0; t < test_cases.size(); ++t) {
        int N = test_cases[t].first;
        std::vector<int> A = test_cases[t].second;
        int B = B_values[t];
        B = std::max(B, -B);

        std::sort(A.begin(), A.end());

        int i = 0, j = 0, match = 0;
        while (i < N && j < N) {
            int D = A[j] - A[i];
            if (D == B) {
                match = 1;
                break;
            } else if (D > B) {
                i++;
            } else {
                j++;
            }
        }

        std::cout << match << std::endl;
    }

    return 0;
}
