#include <bits/stdc++.h>

using namespace std;

int find_new(int n){
    if(n%2==0)
        return n/2;
    else
        return n/2+1;
}

bool check_fight(int a, int b){
    int min_num = min(a,b);
    
    if(abs(a-b)==1){
        if(min_num%2==1)
            return false;
    }
    
    return true;
}

int solution(int n, int a, int b)
{
    int answer = 0;

    while(check_fight(a,b)){
        answer++;
        a=find_new(a);
        b=find_new(b);
    }        

    return answer;
}

int main(void){

    cout<<solution(8,4,7)<<'\n';

    return 0;
}