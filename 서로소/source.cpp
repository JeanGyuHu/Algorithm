#include <bits/stdc++.h>

using namespace std;

int parents[100001];

int find_parent(int x){
    if(parents[x]!=x) 
        parents[x] = find_parent(parents[x]);
    return parents[x];
}

int union_node(int x, int y){
    x = find_parent(x);
    y = find_parent(y);

    if(x>y)
        parents[x]=y;
    else
        parents[y]=x;
}

int main(void){
    int v, e;

    cin>>v>>e;

    for(int i=1; i<=v; i++)
        parents[i]=i;

    bool cycle = false;

    for(int i=0;i<e;i++){
        int a,b;

        cin>>a>>b;

        if(find_parent(a)==find_parent(b)){
            cycle=true;
            break;
        }
        else{
            union_node(a, b);
        }
    }

    if(cycle)
        cout<<"There's cycle\n";
    else
        cout<<"There's no cycle\n";

    return 0;
}