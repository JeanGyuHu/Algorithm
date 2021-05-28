#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> money) {
    
    int dp[100001]={0,};

    dp[0]=1;
    
    for(int i=money[0]; i<=n; i+=money[0])
        dp[i]=1;
    
    for(int i=1; i<money.size(); i++){
        for(int j=1; j<=n; j++){
            if(j>=money[i])
                dp[j] += dp[j-money[i]] % 1000000007;
        }
    }
    
    return dp[n];
}