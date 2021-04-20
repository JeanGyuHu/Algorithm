#include <bits/stdc++.h>

using namespace std;

int solution(int n)
{
    int ans = 0;

    while(n!=0){
        if(n%2==0)
            n/=2;
        else{
            n-=1;
            ans++;
        }
    }

    return ans;
}

int main(void){

    cout<<solution(5)<<'\n';

    return 0;
}