#include <iostream>
#include <unordered_map> // for unordered_map

using namespace std;

void countFreq(int arr[], int n) {
    unordered_map<int, int> hmp; // Declaration of unordered_map to store element frequencies
    
    // Count frequencies of each element in the array
    for (int i = 0; i < n; i++) {
        int key = arr[i];
        if (hmp.find(arr[i]) != hmp.end()) {
            hmp[arr[i]]++;
        } else {
            hmp[arr[i]] = 1;
        }
    }
    
    // Print the frequencies
    for (auto itr = hmp.begin(); itr != hmp.end(); itr++) {
        cout << itr->first << " " << itr->second << endl;
    }
}

int main() {
    int arr[] = {3112102, 3112500, 3112501, 3112700, 3112800};

    int n = sizeof(arr) / sizeof(arr[0]);

    countFreq(arr, n);

    return 0;
}
