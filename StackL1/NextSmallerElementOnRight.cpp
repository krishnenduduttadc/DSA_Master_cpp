#include <iostream>
#include <stack>
using namespace std;

int* help_classmate(int* arr, int n)
{
    int* ans = new int[n];
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[i] < arr[st.top()]){
            int idx = st.top();
            st.pop();
            ans[idx] = arr[i];
        }
        st.push(i);
    }
    while(!st.empty()){
        int idx = st.top();
        st.pop();
        ans[idx] = -1;
    }

    return ans;
}

int main() {
    int arr[] = {4, 8, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    int* result = help_classmate(arr, n);

    cout << "Resulting array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] result; // Free dynamically allocated memory

    return 0;
}
