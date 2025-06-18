#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


    vector<int> leastPrimeFactor(int n) {
        vector<int> spf(n + 1);

        for (int i = 1; i <= n; i++) {
            spf[i] = i;
        }

        for (int i = 2; i * i <= n; i++) {
            if (spf[i] == i) { 
                for (int j = i * i; j <= n; j += i) {
                    if (spf[j] == j) { 
                        spf[j] = i;
                    }
                }
            }
        }

        return spf;
    }


int main() {
   

    int n = 10;

    vector<int> result = leastPrimeFactor(n);

    cout << "Least Prime Factors from 1 to " << n << ": ";
    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
