#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int X, d[1000001];

void solution(int a, int cnt){

    if(d[a] > cnt){
        d[a] = cnt;
    }
    else 
        return;
    
    if(a==1)
        return;
   
    if(a%3==0)
        solution(a/3, cnt+1);
    
    if(a%2==0)
        solution(a/2, cnt+1);

    solution(a-1, cnt+1);
}

int main(void){

    cin>>X;

    for(int i=0; i<=X; i++)
        d[i]=INF;

    solution(X, 0);

    cout<<d[1]<<'\n';

    return 0;
}