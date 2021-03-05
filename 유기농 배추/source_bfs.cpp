#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int t, n, m, k;
int field[50][50];
int visited[50][50];

int dx[4] = {-1, 1, 0, 0};  //상하좌우
int dy[4] = {0, 0, -1, 1};

int result;

queue<pair<int, int> > q;

void bfs(){

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0 || nx>=n || ny<0 || ny>=m)
                continue;
            else{
                if(field[nx][ny]==1 && visited[nx][ny]==0){
                    visited[nx][ny]=1;
                    q.push(make_pair(nx, ny));
                }
                
            }
        }
    }
}

void solution(){

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]==0&&field[i][j]==1){
                q.push(make_pair(i,j));
                visited[i][j]=1;
                bfs();
                result++;
            }
        }
    }
    cout<<result<<'\n';
}

int main(void){

    cin>>t;

    for(int tc=0; tc<t; tc++){
        
        for(int i=0; i<50; i++){
            memset(field[i], 0, sizeof(int)*50);
            memset(visited[i], 0, sizeof(int)*50);
        }
        

        cin>>m>>n>>k;

        result = 0;
        
        for(int i=0; i<k; i++){
            int x,y;
            cin>>x>>y;
            field[y][x] = 1;
        }

        solution();     
    }

    return 0;
}