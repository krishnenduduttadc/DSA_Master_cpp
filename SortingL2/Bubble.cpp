#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    int c=0;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                c++;
            }
        }
    }
    cout<<c<<endl;
}

int main() {
    int arr[] = {4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted array: \n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
