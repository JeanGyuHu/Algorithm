#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        if(st.empty() || st.top() != s[i]) st.push(s[i]);
        else if(st.top()==s[i]) st.pop();
    }

    if(st.empty())
        return 1;
        
    return 0;
}

int main(void){

    cout<<solution("baabaa")<<'\n';

    return 0;
}