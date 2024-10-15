#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T;
    std::cin >> T;
    
    while (T--) {
        int N, B;
        std::cin >> N >> B;
        B = std::max(B, -B);
        std::vector<int> A(N);
        
        for (int i = 0; i < N; i++) {
            std::cin >> A[i];
        }
        
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

/*
3
6 78
5 10 3 2 50 80
2 30
-10 20
4 5
1 2 3 4

*/