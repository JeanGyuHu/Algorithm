#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int st=0;

    for(int i=0; i<s.length(); i++){
        if(s[i]=='(')
            st++;
        else if(s[i]==')')
            st--;
        if(st<0)
            answer=false;
    }

    if(st!=0)
        answer=false;
    
    return answer;
}

int main(void){

    cout<<solution("()()")<<'\n';
    cout<<solution("(())()")<<'\n';
    cout<<solution(")()(")<<'\n';
    cout<<solution("(()(")<<'\n';

    return 0;
}