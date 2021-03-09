#include <bits/stdc++.h>

using namespace std;

string solution(int n) {
    string answer = "";

    while(n!=0){
        answer="412"[n%3]+answer;
        n = n/3 - (n%3==0);     //0이 없어 3이 배수 일떄 자릿수가 변하지 않는다.
    }
    return answer;
}

int main(void){

    cout<<solution(10)<<'\n';

    return 0;
}