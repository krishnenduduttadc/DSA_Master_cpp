#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class SeiveofErastostenins {
public:
    static void main() {
        vector<bool> myseive = seive(20);
        for (int i = 0; i < myseive.size(); i++) {
            cout << i << " " << (myseive[i] ? "true" : "false") << endl;
        }
    }

    static vector<bool> seive(int n) {
        vector<bool> arr(n + 1, true);
        arr[0] = false;
        arr[1] = false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (arr[i]) {
                for (int j = i * i; j <= n; j += i) {
                    arr[j] = false;
                }
            }
        }
        return arr;
    }
};

int main() {
    SeiveofErastostenins::main();
    return 0;
}
