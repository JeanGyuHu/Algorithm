#include <bits/stdc++.h>

using namespace std;

int N,M;
int arr[200][200];

int dx[4] = {-1, 1, 0, 0};            //상 하 좌 우
int dy[4] = {0, 0, -1, 1};

int bfs(int x, int y){

    queue<pair<int, int> > q;
    q.push(make_pair(x, y));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0||ny<0||nx>N-1||ny>M-1) continue;
            if(arr[nx][ny]==0) continue;

            if(arr[nx][ny]==1){
                arr[nx][ny] = arr[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    return arr[N-1][M-1];
}

int main(void){

    cin>>N>>M;

    for(int i =0;i<N;i++)
        for(int j = 0 ;j < M; j++)
            scanf("%1d", &arr[i][j]);

    cout<<bfs(0,0)<<endl;

    return 0;
}