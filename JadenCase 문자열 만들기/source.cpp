#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";

    if(s[0]>='a' && s[0]<='z'){
        s[0] += 'A'-'a';
    }
    
    for(int i=1; i<s.length(); i++){
        if(s[i-1]==' ' && (s[i]>='a' && s[i]<='z')){
            cout<<"in=============1\n";
            s[i] += 'A'-'a';
        }
        else if(s[i-1]!=' ' && (s[i]>='A' && s[i]<='Z')){
            cout<<"in=============2\n";
            s[i] -= 'A'-'a';
        }
    }

    answer=s;

    return answer;
}

int main(void){

    cout<<solution("3people unFollowed me")<<'\n';

    return 0;
}