#include <iostream>
using namespace std;

void set(int x) {
    for (int i = 0; i < 32; i++) {
        if ((x & (1 << i)) != 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int x = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8); //[1,3,4,8]
    int y = (1 << 3) | (1 << 6) | (1 << 8) | (1 << 9); //[3,6,8,9]

    cout << "\nUnion------------" << endl;
    int unionSet = x | y;
    cout << unionSet << endl;
    set(unionSet);

    cout << "\nIntersection------------" << endl;
    int intersection = x & y;
    cout << intersection << endl;
    set(intersection);

    cout << "\nDifference------------" << endl;
    int difference = x & (~y);
    cout << difference << endl;
    set(difference);

    cout << "\nComplement------------" << endl;
    int complement = ~x;
    cout << complement << endl;
    set(complement);

    return 0;
}
