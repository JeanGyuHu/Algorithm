#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int dp[51];
vector<pair<int, int> > maps[51];

void dijkstra(int start){
    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(start, 0));

    dp[start]=0;

    while(!pq.empty()){
        int now = pq.top().first;
        int dist = -pq.top().second;

        pq.pop();

        if(dp[now] < dist) continue;

        for(int i=0; i<maps[now].size(); i++){
            int now2 = maps[now][i].first;
            int cost = dist+maps[now][i].second;

            if(dp[now2] > cost){
                dp[now2] = cost;
                pq.push(make_pair(now2, -cost));
            }
        }
    }

}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for(int i=1; i<=N; i++)
        dp[i]=INF;
    
    for(int i=0; i<road.size(); i++){
        int a = road[i][0];
        int b = road[i][1];
        int dis = road[i][2];

        maps[a].push_back(make_pair(b,dis));
        maps[b].push_back(make_pair(a,dis));
    }

    dijkstra(1);

    for(int i=1; i<=N; i++)
        if(dp[i] <= K)
            answer++;
    

    return answer;
}

int main(void){


    return 0;
}