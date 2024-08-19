#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 12;         // 00001100 in binary
    int b = 7;          // 00000111 in binary
    int result = a & b; // 00000100 in binary, which is 4 in decimal
    cout << result<<endl;

    result = a | b;
    cout << result<<endl;

    result = a ^ b;
    cout << result<<endl;

    result = ~a; 
    cout<<result<<endl;

    result = a << 2;
    cout<<result<<endl;

    result = a >> 2;
    cout<<result<<endl;

    if((a&(1<<2))!=0){
        cout<<"1";
    }else{
        cout<<"0";
    }

    return 0;
}