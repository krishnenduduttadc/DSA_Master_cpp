#include <iostream>
#include <unordered_map>

using namespace std;

void solution(int arr[], int n) {
    unordered_map<int, int> fmap; // Frequency map
    unordered_map<int, int> smap; // Start index map
    int si = 0; // Start index of the smallest subarray with highest frequency element
    int ei = 0; // End index of the smallest subarray with highest frequency element
    int len = ei - si + 1; // Length of the smallest subarray
    int hfreq = 0; // Highest frequency found

    for (int i = 0; i < n; i++) {
        fmap[arr[i]]++;
        
        if (fmap[arr[i]] == 1) {
            smap[arr[i]] = i;
        }

        if (fmap[arr[i]] > hfreq) {
            hfreq = fmap[arr[i]];
            si = smap[arr[i]];
            ei = i;
            len = ei - si + 1;
        } else if (fmap[arr[i]] == hfreq) {
            int current_len = i - smap[arr[i]] + 1;
            if (current_len < len) {
                hfreq = fmap[arr[i]];
                si = smap[arr[i]];
                ei = i;
                len = current_len;
            }
        }
    }

    cout << arr[si] << endl;
    cout << si << endl;
    cout << ei << endl;
}

int main() {
    int arr[] = {1, 3, 2, 4, 2, 3, 4, 2, 5, 6, 5, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    solution(arr, n);
    return 0;
}
