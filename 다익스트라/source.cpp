#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

    int n,m,start;
    int d[100000];
    bool visited[100000];
    vector<pair<int,int> > graph[100000];

int getSmallestNode(){
    int min_value = INF;
    int idx=0;

    for(int i=0; i<n; i++){
        if(d[i] < min_value && !visited[i]){
            min_value = d[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(start){

    d[start] = 0;
    visited[start] = true;

    for(int i=0; i<graph[start].size(); i++) d[graph[start][i].first] = graph[start][i].second;

    for(int i=0; i<n-1; i++){
        int now = getSmallestNode();
        visited[now]=true;

        for(int j=0; j<graph[now].size(); j++){
            d[graph[now][j].first] = min(d[graph[now][j].first], d[now] + graph[now][j].second);
        }
    }
}

int main(void){

    cin>>n>>m>>start;

    for (int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
    }

    fill_n(d, 100000,INF);

    dijkstra(start);

    for(int i=0; i<n; i++){
        if(d[i]==INF)
            cout<<"INFINITY"<<'\n';
        else
            cout<<d[i]<<'\n';
    }


    return 0;
}

//노드가 5000개 이하일때 가능
//10000개가 넘어가는 문제는 우선순위 큐