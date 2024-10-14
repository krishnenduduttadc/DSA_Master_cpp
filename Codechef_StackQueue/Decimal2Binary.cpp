#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 101
int a[MAX_SIZE];
int top = -1;

void push(int ele){
    if(top<=MAX_SIZE-1){
        a[++top]=ele;
    }
    else{
        cout<<"Stack is full. Cannot push: "<<ele<<"\n";
    }
}

int pop(){
    if(top>=0){
        int ele = a[top];
        top--;
        return ele;
    }
    else{
        cout<<"Stack is empty. Cannot pop.\n";
        return -1;
    }
}

bool isEmpty(){
    return top==-1;
}

int size(){
    return top+1;
}

void decimalToBinary(int decimal){
    while (decimal > 0) {
        int Remainder = decimal % 2;
        push(Remainder);
        decimal/=2;
    }

    if(isEmpty()) {
        cout<<"0\n"; // Special case for decimal = 0
        return;
    }

    // string ans;
    while(!isEmpty()){
        cout<<pop();
    }
    cout<<"\n";
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int decimal;
        cin>>decimal;
        decimalToBinary(decimal);
    }
    return 0;
}


/*
3
10
15
18
*/