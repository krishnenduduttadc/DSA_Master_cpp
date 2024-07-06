#include <iostream>
using namespace std;

int main() {
    int n = 5; // number of posts
    int k = 3; // number of colors

    long same = k * 1;
    long diff = k * (k - 1);
    long total = same + diff;

    for (int i = 3; i <= n; i++) {
        same = diff * 1;
        diff = total * (k - 1);
        total = same + diff;
    }

    cout << total << endl;

    return 0;
}
