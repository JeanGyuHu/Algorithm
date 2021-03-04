#include <bits/stdc++.h>

using namespace std;

int N,M;
int arr[1000][1000];

bool dfs(int x, int y){
    if(arr[x][y]==1)
        return false;
    else if(x<0||y<0||x>=N||y>=M)
        return false;
    else{
        arr[x][y] = 1;
    
        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x,y-1);
        dfs(x,y+1);
        
        return true;
    }
}

int main(void){
    int count=0;

    cin>>N>>M;

    for(int i =0 ;i<N;i++)
        for(int j = 0 ; j<M;j++)
            scanf("%1d", &arr[i][j]);

    for(int i =0 ;i<N;i++)
        for(int j = 0 ; j<M;j++)
            if(dfs(i,j))
                count++;    
    
    cout<<count<<endl;

    return 0;
}