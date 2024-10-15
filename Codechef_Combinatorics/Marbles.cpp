#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++){
	    long long int n,k;
	    cin>>n>>k;
	    
	    long long int sum =1;
	    
	    for(long long int i=1;i<k;i++)
	    {
	        sum = sum*((n-k)+i)/i;
	    }
	    cout<<sum<<endl;
	}
	return 0;
}



/*
2
10 10
30 7
*/