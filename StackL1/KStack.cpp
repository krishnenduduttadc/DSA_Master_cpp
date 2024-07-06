#include <iostream>
#include <climits>
using namespace std;

class KStack {
private:
    int* arr;    // Array to store elements of all stacks
    int* top;    // Array to store top index of each stack
    int* next;   // Array to store next available index in arr
    int n, k;    // n is size of array arr, k is number of stacks
    int free;    // Next available index in arr

public:
    KStack(int k1, int n1) {
        k = k1;
        n = n1;
        arr = new int[n];
        top = new int[k];
        next = new int[n];

        for (int i = 0; i < k; i++) {
            top[i] = -1;
        }

        free = 0;
        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }

    void push(int val, int sn) {
        if (free == -1) {
            cout << "Stack Overflow" << endl;
            return;
        }

        int idx = free;
        arr[idx] = val;

        free = next[idx];

        next[idx] = top[sn];
        top[sn] = idx;
    }

    int pop(int sn) {
        if (top[sn] == -1) {
            cout << "Stack Underflow" << endl;
            return INT_MAX;
        }

        int idx = top[sn];
        top[sn] = next[idx];

        next[idx] = free;
        free = idx;

        return arr[idx];
    }

    ~KStack() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }
};

int main() {
    int k = 3, n = 10;
    KStack ks(k, n);

    ks.push(15, 2);
    ks.push(45, 2);

    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

    return 0;
}
