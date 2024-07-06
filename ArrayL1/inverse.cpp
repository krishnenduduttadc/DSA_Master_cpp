#include <iostream>
using namespace std;

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}

int* inverse(int a[], int n) {
    int* b = new int[n];

    for (int i = 0; i < n; i++) {
        b[a[i]] = i;
    }

    return b;
}

int main() {
    int n = 5;
    int a[] = {4, 0, 2, 3, 1};

    int* inv = inverse(a, n);
    display(inv, n);

    delete[] inv; // Don't forget to free the allocated memory

    return 0;
}
