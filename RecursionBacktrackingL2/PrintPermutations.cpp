#include <iostream>
using namespace std;

void permute(int boxes[], int ci, int ti) {
    if (ci > ti) {
        for (int i = 0; i < ti; i++) {
            cout << boxes[i];
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < ti; i++) {
        if (boxes[i] == 0) {
            boxes[i] = ci;
            permute(boxes, ci + 1, ti);
            boxes[i] = 0;
        }
    }
}

int main() {
    int nboxes = 3;
    int ritems = 2;
    int boxes[nboxes] = {0};
    permute(boxes, 1, ritems);
    return 0;
}
