#include <bits/stdc++.h>
using namespace std;

int parent[100000];


int dsuFind(int a){
    if(parent[a]==a) return a;
    return dsuFind(parent[a]);
}

void dsuUnion(int a, int b) {
    int leader_a = dsuFind(a);
    int leader_b = dsuFind(b);
    if(leader_a!=leader_b)
    {
        parent[leader_b] = leader_a;
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        parent[i] = i;
    }
    for(int i=0; i<m; i++)
    {
        string command;
        cin>>command;
        if(command == "union")
        {
            int a, b;
            cin>>a>>b;
            dsuUnion(a, b);
        }
        else if(command == "find"){
            int a;
            cin>>a;
            cout<<dsuFind(a)<<endl;
        }
    }
}


/*
5 7
union 1 0
union 2 1
find 0
find 1
find 2
find 3
find 4
*/