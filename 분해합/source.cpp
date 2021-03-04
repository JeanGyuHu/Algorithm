#include <bits/stdc++.h>

using namespace std;

int solution(int num){

    for(int i=0; i<num;i++){
        int sum=0;
        int x=i;
        while(x!=0){
            sum+=x%10;
            x = x / 10;
        }
        if(sum+i==num)
            return i;
    }

    return 0;
}

int main(void){

    int n;

    cin>>n;

    cout<<solution(n)<<'\n';

    return 0;
}