#include <iostream>
#include <vector>
using namespace std;

int mean(vector<int>& vec) {
    int n = vec.size();
    int sum = 0;
    
    for (int i = 0; i < n; ++i) {
        sum += vec[i];
    }
    
    int res = sum / n;
    return res;
}

int main() {
    vector<int> vec;
    
    for (int i = 0; i < 5; ++i) {
        vec.push_back(i);
    }
    
    cout << mean(vec) << endl;
    
    return 0;
}
