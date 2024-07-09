#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    while(!st.empty()){
        int rem=st.top();
        cout << rem << endl;
        st.pop();
    }

    return 0;
}