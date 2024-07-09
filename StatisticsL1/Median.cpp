#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int median(vector<int>& vec) {
    int n = vec.size();
    sort(vec.begin(), vec.end());
    
    if (n % 2 == 0) {
        return (vec[n / 2 - 1] + vec[n / 2]) / 2;
    } else {
        return vec[(n - 1) / 2];
    }
}

int main() {
    vector<int> vec;
    
    for (int i = 0; i < 5; ++i) {
        vec.push_back(i);
    }
    
    cout << "Original vector: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Median: " << median(vec) << endl;
    
    return 0;
}
