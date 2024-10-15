#include <bits/stdc++.h>
using namespace std;

int parent[100000];
int setSize[100000];


int dsuFind(int a){
    if(parent[a]==a) return a;
    return parent[a] = dsuFind(parent[a]);
}

void dsuUnion(int a, int b) {
    int leader_a = dsuFind(a);
    int leader_b = dsuFind(b);
    if(leader_a!=leader_b)
    {
        if(setSize[leader_b]<setSize[leader_a])
        {
            swap(leader_a, leader_b);
        }
        parent[leader_b] = leader_a;
        setSize[leader_a]+=setSize[leader_b];
    }
}

int main() {
	int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        parent[i] = i;
        setSize[i] = 1;
    }
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        dsuUnion(a, b);
    }
    int q;
    cin>>q;
    for(int i=0; i<q; i++)
    {
        int x, y;
        cin>>x>>y;
        if(dsuFind(x)==dsuFind(y))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}


/*
10 4
1 2
2 3
3 4
4 5
8
5 1
1 2
2 3
4 5
0 1
0 9
9 8
8 7*/