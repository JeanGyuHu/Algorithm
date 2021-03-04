#include <bits/stdc++.h>

using namespace std;

int parents[100001];
vector<pair<int, pair<int, int> > > edges;

int find_parent(int x){
    if(x==parents[x])
        return x;
    else
        return parents = find_parent(parents[x]);
}

int union_node(int a, int b){
    
    a=find_parent(a);
    b=find_parent(b);

    if(a<b)
        parents[b]=a;
    else
        parents[a]=b;
}

int main(void){

    int result=0;

    cin>>v>>e;

    for(int i=1; i<=v; i++)
        parent[i]=i;
    
    for(int i=0; i<e; i++){
        int a,b,cost;

        c>>a>>b>>cost;

        edges.push_back(make_pair(cost,make_pair(a, b)));
    }

    sort(edges.begin(), edges.end());

    for(int i=0; i<edges.size(); i++){
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        if(find_parent(a) != find_parent(b)){
            union_parent(a, b);
            result+=cost;
        }
    }

    cout<<result<<'\n';

    return 0;
}