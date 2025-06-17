#include <iostream>
#include <queue>
using namespace std;

// Global max heap for smaller half
priority_queue<int> small;

// Global min heap for larger half
priority_queue<int, vector<int>, greater<int>> large;

void addNum(int num) {
    if (small.size() == large.size()) {
        if (large.empty() || num <= large.top()) {
            small.push(num);
        } else {
            small.push(large.top());
            large.pop();
            large.push(num);
        }
    } else {
        if (num >= small.top()) {
            large.push(num);
        } else {
            large.push(small.top());
            small.pop();
            small.push(num);
        }
    }
}

double findMedian() {
    if (small.size() > large.size()) {
        return small.top();
    } else {
        return (small.top() + large.top()) / 2.0;
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < n; i++) {
        addNum(numbers[i]);
        cout << "Current median after adding " << numbers[i] << ": " << findMedian() << endl;
    }

    return 0;
}
