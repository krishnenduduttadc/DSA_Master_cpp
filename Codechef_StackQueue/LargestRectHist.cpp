#include <iostream>
#include <stack>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int N;
	    cin>>N;
	    long A[N];
	    for (int i=0; i<N; i++)
	        cin>>A[i];
	    stack<int> S;
	    S.push(-1);
	    long res = 0;
	    for (int i=0; i<N; i++) {
	        int x = A[i];
	        while (S.top() != -1 && A[S.top()]>=x) {
	            int y = S.top();
	            S.pop();
	            res = max(res, A[y]*(i-1-S.top()));
	        }
	        S.push(i);
	    }
	        while (S.top() != -1) {
	            int y = S.top();
	            S.pop();
	            res = max(res, A[y]*(N-1-S.top()));
	        }
	    cout<<res<<endl;
	}
	return 0;
}

/*
3
4
2 6 8 4
4
5 10 5 2
2
5 5

*/