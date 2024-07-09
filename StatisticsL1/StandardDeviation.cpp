#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double mean(vector<int>& vec) {
    int n = vec.size();
    int sum = 0;
    
    for (int i = 0; i < n; ++i) {
        sum += vec[i];
    }
    
    double res = static_cast<double>(sum) / n;
    return res;
}

double variance(vector<int>& vec, double m) {
    double res = 0;
    int n = vec.size();
    
    for (int i = 0; i < n; ++i) {
        res += pow(vec[i] - m, 2);
    }
    
    return res / n;
}

double standardDeviation(vector<int>& vec, double m) {
    return sqrt(variance(vec, m));
}

int main() {
    vector<int> vec;
    
    for (int i = 0; i < 5; ++i) {
        vec.push_back(i);
    }
    
    double m = mean(vec);
    cout << "Mean: " << m << endl;
    
    double mySD = standardDeviation(vec, m);
    cout << "Standard Deviation: " << mySD << endl;
    
    return 0;
}
