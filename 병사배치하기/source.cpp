#include <bits/stdc++.h>

using namespace std;

int main(void){

    int N, dp[2000];
    vector<int> sol;

    cin>>N;

    for(int idx=0; idx<N; idx++){
        int x;
        cin>>x;
        sol.push_back(x);
    }

    for(int i=0; i<N; i++) dp[i]=1;

    for(int i=1; i<N; i++){
        for(int j=0; j<i;j++){
            if(sol[i]<sol[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }

    int maxValue=0;

    for(int i=0; i<N; i++)
        maxValue = max(maxValue, dp[i]);

    cout<<N-maxValue<<endl;

    return 0;
}

/*
7
15 11 4 8 5 2 4
*/

//2