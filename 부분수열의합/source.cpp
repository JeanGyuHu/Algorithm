#include <bits/stdc++.h>

using namespace std;

int n,s;
int num[20];
int cnt;

void solution(int sum, int x){
    if(x>=n)
        return;
    if(sum+num[x]==s)
        cnt++;
    
    //이번 항 더한거
    solution(sum+num[x],x+1);
    //이번 항 안더한거
    solution(sum, x+1);
}

int main(void){

    cin>>n>>s;

    for(int i=0; i<n; i++)
        cin>>num[i];

    solution(0,0);

    cout<<cnt<<'\n';

    return 0;
}