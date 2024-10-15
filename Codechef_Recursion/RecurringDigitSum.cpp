#include <iostream>
using namespace std;

int recurrent_sum_of_digits(int n) {
    if (n < 10) 
        return n;
    
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    
    return recurrent_sum_of_digits(sum);
}

int main() {
    int n;
    cin >> n;
    cout << recurrent_sum_of_digits(n) << endl;
    return 0;
}



/*
38
*/