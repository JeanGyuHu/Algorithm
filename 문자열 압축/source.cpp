#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = s.size();

    for(int i=1; i<=s.size()/2; i++){
        int cnt=1;
        string tmp_str;
        string tmp;
        tmp = s.substr(0,i);

        for(int j=i; j<s.size(); j+=i){
            if(tmp==s.substr(j,i)) cnt++;
            else{
                if(cnt>1) tmp_str+=to_string(cnt);
                tmp_str+=tmp;
                tmp = s.substr(j,i);
                cnt=1;
            }
        }
        
        if(cnt>1) tmp_str+=to_string(cnt);
        tmp_str+=tmp;
        
        //cout<<'\n'<<tmp_str<<'\n';

        answer = min(answer, (int)tmp_str.size());
    }

    return answer;
}

int main(void){

    cout<<solution("ababcdcdababcdcd")<<'\n';
    
    return 0;
}