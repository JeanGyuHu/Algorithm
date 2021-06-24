#include <bits/stdc++.h>

using namespace std;

bool maps[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i=0; i<101; i++)
        for(int j=0; j<101; j++)
            maps[i][j]=false;
    
    for(int i=0; i<results.size(); i++){
        int x = results[i][0];
        int y = results[i][1];
        
        maps[x][y]=true;
    }
    
    for(int k=1; k<=n; k++){
        for(int a=1; a<=n; a++){
            for(int b=1; b<=n; b++){
                if(maps[a][k] && maps[k][b])
                    maps[a][b]=true;
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        int cnt=0;
        for(int j=1; j<=n; j++){
            if(maps[i][j] || maps[j][i]) cnt++;
        }
        if(cnt==n-1) answer++;
    }
    
    return answer;
}

int main(void){



    return 0;
}