#include <bits/stdc++.h>

using namespace std;

int isBalanced(string str){

    int left =0, right=0;

    for(char x : str){
        if(x=='(') left++;
        else right++;

        if(left==right)
            return left+right;
    }

    return 0;
}

bool isRight(string str){

    stack<int> s;

    if(str[0]!='(')
        return false;
    
    for(char c : str){
        if(c=='(')
            s.push(c);
        else{
            if(s.empty())
                return false;
            else
                s.pop();
        }
    }
    return true;
}

string recursion(string p){
    
    string u,v, rtn;

    if(p=="") return p;
    
    int idx = isBalanced(p);

    u = p.substr(0,idx);
    v = p.substr(idx);

    if(isRight(u))
        return u + recursion(v);
    else {
        rtn += "(" + recursion(v)+ ")";
        u = u.substr(1,u.length()-2);
        for(char c : u){
            if(c=='(') rtn+=')';
            else rtn+='(';
        }

        return rtn;
    }
}

string solution(string p) {
    
    if(isRight(p)) 
        return p;
    else
        return recursion(p);
}

int main(void){

    cout<<solution("(()())()")<<'\n';   //(()())()
    cout<<solution("()))((()")<<'\n';   //()(())()
    cout<<solution(")(")<<'\n';         //()

    return 0;
}