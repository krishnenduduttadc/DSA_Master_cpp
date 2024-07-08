#include <iostream>
using namespace std;

int l(int n) {
    int x = 0;
    while((1 << x) <= n) {
        x++;
    }
    return x - 1;
}

int solution(int n) {
    if(n == 0) {
        return 0;
    }
    
    int x = l(n);
    int b = x * (1 << (x - 1));
    int m = n - (1 << x) + 1;
    int r = n - (1 << x);
    int a = b + m + solution(r);
    return a;
}

int main() {
    int n = 10;
    cout << solution(n) << endl;
    return 0;
}
