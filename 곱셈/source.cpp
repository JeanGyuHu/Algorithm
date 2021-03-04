#include <bits/stdc++.h>

using namespace std;

long long int A,B,C;

long long int solution(long long int a, long long int m){
    
    if(m==0)
        return 1;

    if(m%2)
        return (solution(a, m-1) * a) % C;

    return ((solution(a, m/2)%C) * (solution(a, m/2)%C)) % C;
}

int main(void){
    
    cin>>A>>B>>C;

    cout<<solution(A,B)<<'\n';

    return 0;
}