#include <iostream>
#include <climits>
using namespace std;

struct KStack {
    int* arr;    // Actual array to store elements
    int* top;    // Top of each stack
    int* next;   // Next entry (free list or link to previous stack element)
    int n, k;    // n = total size of arr, k = number of stacks
    int free;    // Beginning index of free list
};

// Initialize the KStack structure
void initKStack(KStack& ks, int k1, int n1) {
    ks.k = k1;
    ks.n = n1;
    ks.arr = new int[n1];
    ks.top = new int[k1];
    ks.next = new int[n1];

    for (int i = 0; i < k1; i++)
        ks.top[i] = -1;

    ks.free = 0;
    for (int i = 0; i < n1 - 1; i++)
        ks.next[i] = i + 1;
    ks.next[n1 - 1] = -1;
}

// Push val into stack number sn (0-based index)
void push(KStack& ks, int val, int sn) {
    if (ks.free == -1) {
        cout << "Stack Overflow" << endl;
        return;
    }

    int idx = ks.free;
    ks.free = ks.next[idx];

    ks.arr[idx] = val;
    ks.next[idx] = ks.top[sn];
    ks.top[sn] = idx;
}

// Pop from stack number sn (0-based index)
int pop(KStack& ks, int sn) {
    if (ks.top[sn] == -1) {
        cout << "Stack Underflow" << endl;
        return INT_MAX;
    }

    int idx = ks.top[sn];
    ks.top[sn] = ks.next[idx];

    ks.next[idx] = ks.free;
    ks.free = idx;

    return ks.arr[idx];
}

// Free memory
void destroyKStack(KStack& ks) {
    delete[] ks.arr;
    delete[] ks.top;
    delete[] ks.next;
}

int main() {
    int k = 3, n = 10;
    KStack ks;
    initKStack(ks, k, n);

    push(ks, 15, 2);
    push(ks, 45, 2);

    push(ks, 17, 1);
    push(ks, 49, 1);
    push(ks, 39, 1);

    push(ks, 11, 0);
    push(ks, 9, 0);
    push(ks, 7, 0);

    cout << "Popped element from stack 2 is " << pop(ks, 2) << endl;
    cout << "Popped element from stack 1 is " << pop(ks, 1) << endl;
    cout << "Popped element from stack 0 is " << pop(ks, 0) << endl;

    destroyKStack(ks);
    return 0;
}
