#include <bits/stdc++.h>
#define MAX 1e9
#define MIN -1e9

using namespace std;

int N;
int field[100][100];
int visited[100][100];
int maxi=MIN;
int mini=MAX;
int result= 1;
int cnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int height, int x, int y){
    if(x<0 || x>=N || y<0 || y>=N)
        return;
    
    if(height>=field[x][y] || visited[x][y])
        return;

    visited[x][y]=1;

    for(int i=0; i<4;i++){
        dfs(height, x+dx[i], y+dy[i]);
    }
}

void init(){
    cnt=0;
    for(int i=0; i<100; i++){
        memset(visited[i],0, sizeof(int)*100);
    }
}

int main(void){

    cin>>N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>field[i][j];
            mini = min(mini, field[i][j]);
            maxi = max(maxi, field[i][j]);
        }
    }
    
    for (int h=mini; h<maxi; h++){
        init();
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(!visited[i][j] && field[i][j]>h){
                    dfs(h,i,j);
                    cnt++;
                }
            }
        }
        result = max(result, cnt);
    }
    
    cout<<result<<'\n';

    return 0;
}