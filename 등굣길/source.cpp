#include <bits/stdc++.h>

using namespace std;

int maps[101][101];
int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i=0; i<puddles.size(); i++){
        int x = puddles[i][1];
        int y = puddles[i][0];
        
        maps[x][y]=-1;
    }
    
    dp[1][1]=1;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==1 && j==1)
                continue;
            if(maps[i][j]==-1)
                dp[i][j]=0;
            else
                dp[i][j]=(dp[i-1][j] + dp[i][j-1]) % 1000000007;
        }
    }
    
    return dp[n][m];
}