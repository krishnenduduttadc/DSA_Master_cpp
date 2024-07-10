#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

class Pair {
public:
    int i, s, j;
    string psf;

    Pair(int i, int s, int j, string psf) {
        this->i = i;
        this->s = s;
        this->j = j;
        this->psf = psf;
    }
};

void solution(const vector<int>& arr) {
    vector<int> dp(arr.size(), INT_MAX);
    dp[arr.size() - 1] = 0;
    
    for (int i = arr.size() - 2; i >= 0; i--) {
        int steps = arr[i];
        int min_steps = INT_MAX;
        
        for (int j = 1; j <= steps && i + j < arr.size(); j++) {
            if (dp[i + j] != INT_MAX && dp[i + j] < min_steps) {
                min_steps = dp[i + j];
            }
        }

        if (min_steps != INT_MAX) {
            dp[i] = min_steps + 1;
        }
    }
    
    cout << dp[0] << endl;

    deque<Pair> queue;
    queue.emplace_back(0, arr[0], dp[0], "0");
    
    while (!queue.empty()) {
        Pair rem = queue.front();
        queue.pop_front();
        
        if (rem.j == 0) {
            cout << rem.psf << "." << endl;
        }
        
        for (int j = 1; j <= rem.s && rem.i + j < arr.size(); j++) {
            int ci = rem.i + j;
            if (dp[ci] != INT_MAX && dp[ci] == rem.j - 1) {
                queue.emplace_back(ci, arr[ci], dp[ci], rem.psf + "->" + to_string(ci));
            }
        }
    }
}

int main() {
    vector<int> arr = {3, 3, 0, 2, 1, 2, 4, 2, 0, 0};
    solution(arr);
    return 0;
}
