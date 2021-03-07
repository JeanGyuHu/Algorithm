#include <bits/stdc++.h>

using namespace std;

int field[25][25];
int visited[25][25];

int N;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int result[1000];

int bfs(int x, int y){
    
    int rtn=0;

    queue<pair<int, int> > q;

    q.push(make_pair(x,y));

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;

        q.pop();
        rtn++;
        visited[x][y]=1;

        for(int i=0;i<4;i++){
            if((field[x+dx[i]][y+dy[i]] == 1) 
            && !visited[x+dx[i]][y+dy[i]] 
            && (x+dx[i]>=0 && x+dx[i]<N && y+dy[i]>=0 && y+dy[i]<N)){
                q.push(make_pair(x+dx[i],y+dy[i]));
                visited[x+dx[i]][y+dy[i]]=1;
            }
                
        }
    }
    return rtn;
}

int main(void){
    int cnt=0;

    cin>>N;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%1d", &field[i][j]);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(field[i][j]==1 && visited[i][j]==0){
                result[cnt]=bfs(i,j);
                cnt++;
            }
        }
    }

    cout<<cnt<<'\n';

    sort(result,result+cnt);
    
    if (cnt==0)
        cout<<0<<'\n';
    for(int i=0; i<cnt; i++){
        cout<<result[i]<<'\n';
    }
        

    return 0;
}