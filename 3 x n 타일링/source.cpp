#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    
    long long dp[5001]={0,};
    
    if(n%2) return 0;
    
    dp[0]=1;
    dp[2]=3;
    
    for(int i=4; i<=n; i=i+2){
        dp[i] = dp[i-2] * 3;
        for(int j=i-4; j>=0; j=j-2)
            dp[i] += dp[j] * 2;
        dp[i] %= 1000000007;
    }
    
    return dp[n];
}