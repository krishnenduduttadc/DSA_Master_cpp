#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int len;
	cin>>len;
	vector<int>arr;
	for(int i = 0;i<len;i++){
	    int num;
	    cin>>num;
	    arr.push_back(num);
	}
	vector<int>pre(len,0);
	for(int i = 0;i<len;i++){
	    if(i!=0){
	        pre[i] += pre[i-1];
	    }
	    pre[i] += arr[i];
	}
	for(auto e:pre){
	    cout<<e<<" ";
	}
	cout<<"\n";
}


/*
4
5 3 3 13
*/