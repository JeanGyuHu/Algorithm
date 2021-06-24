#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int res[20001];

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int> > maps(n+1, vector<int>(n+1, 0));
    int answer = 0;
    int dist=0;
    queue<int> q;
    
    for(int i=2; i<=n; i++)
        res[i]=INF;
    
    for(int i=0; i<edge.size(); i++){
        int x = edge[i][0];
        int y = edge[i][1];
        
        maps[x][y]=1;
        maps[y][x]=1;
    }
    
    q.push(1);
    
    while(!q.empty()){
        
        int cur=q.front();
        q.pop();
        
        dist = res[cur]+1;
        
        for(int i=1; i<=maps.size(); i++){
            if(maps[cur][i]){
                if(res[i] > dist){
                    q.push(i);
                    res[i]= dist;
                }
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        if(dist-1==res[i]){
            answer++;
        }
    }
        
    return answer;
}