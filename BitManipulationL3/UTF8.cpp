#include <iostream>
#include <vector>
using namespace std;

bool solution(vector<int>& arr) {
    int rbytes = 0;

    for (int val : arr) {
        if (rbytes == 0) {
            if ((val >> 7) == 0b0) {
                rbytes = 0;
            } else if ((val >> 5) == 0b110) {
                rbytes = 1;
            } else if ((val >> 4) == 0b1110) {
                rbytes = 2;
            } else if ((val >> 3) == 0b11110) {
                rbytes = 3;
            } else {
                return false;
            }
        } else {
            if ((val >> 6) == 0b10) {
                rbytes--;
            } else {
                return false;
            }
        }
    }

    return rbytes == 0;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};

    cout << boolalpha << solution(arr) << endl;

    return 0;
}
