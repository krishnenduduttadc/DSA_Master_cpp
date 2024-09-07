#include <bits/stdc++.h>
using namespace std;

int medianOfThree(int arr[], int l, int h) {
    int mid = l + (h - l) / 2;
    if (arr[l] > arr[mid])
        swap(arr[l], arr[mid]);
    if (arr[l] > arr[h])
        swap(arr[l], arr[h]);
    if (arr[mid] > arr[h])
        swap(arr[mid], arr[h]);    
    return mid;
}

int partition(int arr[],int l,int h){
   
    //int medianIndex  = medianOfThree(arr, l, h);
    //swap(arr[l], arr[medianIndex]);
    int piv=arr[l];
    int left=l+1;
    int right=h;
    
    while(left<=right){
        while(left<=right && arr[left]<piv){
            left++;
        }
        while(left<=right && arr[right]>piv){
            right--;
        }
        if(left<=right){
            swap(arr[left],arr[right]);
            left++;
            right--;
            
        }
    }
    swap(arr[l],arr[right]);
    return right;
}


void rquicksort(int arr[], int l, int h)
{
    if (l < h)
    {
        int pivot = partition(arr, l, h);
        rquicksort(arr, l, pivot - 1);
        rquicksort(arr, pivot + 1, h);
    }
}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int l = 0;
    int h = n - 1;


    rquicksort(arr, 0, h);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
