#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> small;   // max heap for smaller half
    priority_queue<int, vector<int>, greater<int>> large;  // min heap for larger half

public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
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
            if (small.top() <= num) {
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
};

int main() {
    // Create an instance of MedianFinder
    MedianFinder medianFinder;

    // Hardcoded array of numbers to be added
    int numbers[] = {1, 2, 3, 4, 5};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    // Add numbers to the MedianFinder and print the median each time
    for (int i = 0; i < n; i++) {
        medianFinder.addNum(numbers[i]);
        cout << "Current median after adding " << numbers[i] << ": " << medianFinder.findMedian() << endl;
    }

    return 0;
}
