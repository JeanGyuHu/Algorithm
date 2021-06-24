#include <bits/stdc++.h>

using namespace std;

//toupper(), tolower() 함수로 간단하게 가능
string solution(string s) {

    if(s[0]>='a' && s[0]<='z'){
        s[0] += 'A'-'a';
    }
    
    for(int i=1; i<s.length(); i++){
        if(s[i-1]==' ' && (s[i]>='a' && s[i]<='z'))
            s[i] += 'A'-'a';
        else if(s[i-1]!=' ' && (s[i]>='A' && s[i]<='Z'))
            s[i] -= 'A'-'a';
    }

    return s;
}

int main(void){

    cout<<solution("3people unFollowed me")<<'\n';

    return 0;
}