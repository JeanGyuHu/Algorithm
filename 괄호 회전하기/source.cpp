#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

bool is_right(string s){
    int sm=0,mi=0,bi=0;
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        if(s[i]=='(') st.push(s[i]);
        else if(s[i]=='{') st.push(s[i]);
        else if(s[i]=='[') st.push(s[i]);
        else {
            if(st.empty())
                return false;

            if(s[i]==')'){
                if(st.top() !='(')
                    return false;
                else
                    st.pop();
            }
            

            if(s[i]=='}') {
                if(st.top() !='{')
                    return false;
                else
                    st.pop();
            }
            if(s[i]==']') {
                if(st.top() !='[')
                return false;
            else
                st.pop();
            }
        }
    }
    if(!st.empty())
        return false;
    return true;
}
string first_to_end(string s){

    for(int i=0; i<s.size()-1; i++) swap(s[i],s[i+1]);

    return s;
}

int solution(string s) {
    int answer = 0;
    int t = s.size()-1;

    for(int i=0; i<t; i++){
        if(is_right(s))
            answer++;
        s = first_to_end(s);
    }

    return answer;
}

int main(void){

    string s = "[][][]";

    cout<<solution(s)<<'\n';
    return 0;
}