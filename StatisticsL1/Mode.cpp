#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int mode(vector<int>& arr) {
    unordered_map<int, int> freqMap;
    
    // Populate the frequency map
    for (int num : arr) {
        freqMap[num]++;
    }
    
    // Find the mode
    int modeElement = 0;
    int maxFreq = 0;
    for (auto& pair : freqMap) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            modeElement = pair.first;
        }
    }
    
    return modeElement;
}

int main() {
    vector<int> arr = {5, 4, 4, 3, 3, 2, 1};
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    int result = mode(arr);
    cout << "Mode: " << result << endl;
    
    return 0;
}
