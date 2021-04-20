#include <bits/stdc++.h>

using namespace std;

int dp[100001];

int solution(int n) {

    dp[1]=dp[2]=1;

    for(int i=3; i<=n; i++)
        dp[i] = (dp[i-1]+dp[i-2]) % 1234567;

    return dp[n];
}

int main(void){

    cout<<solution(100000);    


    return 0;
}