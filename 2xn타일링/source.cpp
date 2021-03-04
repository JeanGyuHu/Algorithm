#include <bits/stdc++.h>

using namespace std;

int n;
int d[1001];

//완전 탐색 시간 초과 -> Dp

void solution(){
    d[1]=1;
    d[2]=2;

    for(int i=3;i<=n ;i++){
        d[i]=(d[i-1]+d[i-2])%10007;
    }
}

int main(void){
   
    cin>>n;

    solution();

    cout<<d[n]<<'\n';

    return 0;
}