#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m ,start;
vector<pair<int, int> > graph[100000];

int d[100000];

void dijkstra(int start){
    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(0, start));

    d[start]=0;

    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[now] < dist) continue;

        for(int i=0;i<graph[now].size(); i++){
            int cost = dist + graph[now][i].first;

            if(cost < d[graph[now][i].first]){
                d[graph[now][i].second] = cost;
                pq.push(make_pair(-cost, graph[now][i].second));
            }
        }

    }
}

int main(void){

    cin>>n>>m>>start;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;

        graph[a].push_back(make_pair(c,b));
    }

    fill_n(d, 100000, INF);

    dijkstra(start);

    for(int i=1; i<n; i++){
        if(d[i]==INF)
            cout<<"INFINITY"<<'\n';
        else{
            cout<<d[i]<<'\n';
        }
    }

    return 0;
}