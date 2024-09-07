#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1=m-l+1;
    int n2=r-m;
    int left[n1];
    int right[n2];
    
    for(int i=0;i<n1;i++){
        left[i]=arr[l+i];
    }
    
    for(int j=0;j<n2;j++){
        right[j]=arr[m+1+j];
    }
    int i = 0, j = 0, k = l;
    
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    
     while (i < n1) {
         arr[k]=left[i];
         i++;
         k++;
     }
    
    while(j<n2){
        arr[k]=right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    mergeSort(arr,0,n-1);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
