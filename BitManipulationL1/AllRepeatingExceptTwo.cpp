#include <iostream>
#include <vector>
using namespace std;

void solution(vector<int>& arr) {
    int xxory = 0;

    for(int val : arr) {
        xxory = xxory ^ val;
    }

    int rsbm = xxory & -xxory;

    int x = 0;
    int y = 0;

    for(int val : arr) {
        if((val & rsbm) == 0) {
            x = x ^ val;
        } else {
            y = y ^ val;
        }
    }

    if(x < y) {
        cout << x << endl;
        cout << y << endl;
    } else {
        cout << y << endl;
        cout << x << endl;
    }
}

int main() {
    vector<int> arr = {2, 2, 3, 3, 6, 6, 9, 1};
    solution(arr);
    return 0;
}
