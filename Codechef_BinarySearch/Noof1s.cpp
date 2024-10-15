#include <bits/stdc++.h>

using namespace std;

int firstOccurrence(int arr[], int n, int target) {
    int l=-1;
    int r=n;
    while(r-l>1){
        int middle=(l+r)/2;
        if(arr[middle]>=target){
            r=middle;
        }else{
            l=middle;
        }
    }
    return r;
}

int main() {
    int n; // Declare a variable to store the size of the array
    cin >> n; // Take input for the size of the array

    int binaryArray[n]; // Declare the array to store the binary numbers
    for (int i = 0; i < n; i++) {
        cin >> binaryArray[i]; // Take input for each element of the array
    }

    int first_one_index = firstOccurrence(binaryArray, n, 1);


    int total_ones = n - first_one_index;
    cout << total_ones << endl;

}

/*
7
0 0 1 1 1 1 1
*/