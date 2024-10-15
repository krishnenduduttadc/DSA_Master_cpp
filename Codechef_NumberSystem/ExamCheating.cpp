#include <iostream>
using namespace std;

int t,a,b;

int countDivisors(int n) {
    int divisors = 0;
    
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) {
                divisors++;
            } else {
                divisors += 2;
            }
        }
    }
    
    return divisors;
}
int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int a,b;
        cin >> a >> b;
        
        if(a==b)
            cout<<-1<<endl;
        else
            cout<< countDivisors(abs(a-b)) << endl;
    }
    
    return 0;
}


/*
1
2 6
*/