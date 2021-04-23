#include <bits/stdc++.h>

using namespace std;

bool check_num(string s){
    int cnt=0;
    for(int i=0; i<s.length(); i++)
        if(s[i]=='@')
            cnt++;
    return cnt==1;
}

bool check_top_level_domain(string s){
    string tmp = s.substr(s.length()-3);

    if(tmp=="com" || tmp=="org" || tmp=="net")
        return true;

    return false;
}

bool check_contain(string s){
    
    for(int i=0; i<s.length(); i++){
        if(s[i]!='.' && s[i]!='@' && (s[i]<'a' || s[i]>'z') && (s[i]<'A' || s[i]>'Z'))
            return false;
    }
    return true;
}

int solution(vector<string> v){
    int answer=0;

    for(int i=0; i<v.size(); i++){
        if(!check_num(v[i])) continue;
        if(!check_top_level_domain(v[i])) continue;
        if(!check_contain(v[i])) continue;    
        answer++;
   }
   return answer;
}

int main(void){

    vector<string> v;

    v.push_back("d@ddd.com");
    v.push_back("se.ei@jiji.org");
    v.push_back("are@jei@jojo.net");

    cout<<solution(v)<<'\n';

    return 0;
}