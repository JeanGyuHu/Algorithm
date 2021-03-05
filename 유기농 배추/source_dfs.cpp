#include <bits/stdc++.h>

using namespace std;

int t,n,m,k;

int field[50][50];
int visited[50][50];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int result;

void dfs(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m)
        return;

    if(visited[x][y] || field[x][y]==0)
        return;

    visited[x][y]=1;

    for(int i=0;i<4;i++)
        dfs(x+dx[i], y+dy[i]);
    
}

int main(void){

    cin>>t;

    for(int tc=0; tc<t; tc++){

        for(int i=0;i<50;i++){
            memset(field[i], 0, sizeof(int)*50);
            memset(visited[i], 0, sizeof(int)*50);
        }
        
        result=0;

        cin>>m>>n>>k;

        for(int i=0; i<k; i++){
            int x,y;
            cin>>x>>y;
            field[y][x]=1;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(field[i][j]==1&&visited[i][j]==0){
                    dfs(i,j);
                    result++;
                }
            }
        }
        cout<<result<<'\n';
    }

    return 0;
}