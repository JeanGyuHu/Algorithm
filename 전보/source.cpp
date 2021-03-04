#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m, c;    //도시 개수, 통로 개수, 시작 지점
vector<pair<int,int> > graph[30001];
int dp[30001];

void dijkstra(){
    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(c, 0));

    dp[c]=0;

    while(!pq.empty()){
        int time = -pq.top().second;
        int now = pq.top().first;

        pq.pop();

        if(dp[now]< time) continue;

        for(int i=0; i<graph[now].size(); i++){
            int cost = time + graph[now][i].second;
            if(cost < dp[graph[now][i].second]){
                dp[graph[now][i].first] = cost;
                pq.push(make_pair(graph[now][i].first, -cost));
            }
        }
    }
}

int main(void){

    int cnt=0;

    cin>>n>>m>>c;

    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;

        graph[x].push_back(make_pair(y,z));
    }

    fill_n(dp, 30001, INF);

    dijkstra();

    int maxValue=-1;

    for(int i=1;i<=n;i++){
        if(dp[i]!=INF&&i!=c)
            cnt++;
        maxValue = max(maxValue, dp[i]);
    }

    cout<<cnt<<' '<<maxValue<<'\n';

    return 0;
}