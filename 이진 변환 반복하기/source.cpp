#include <bits/stdc++.h>

using namespace std;

string trans_binary(string s){
    string rtn;

    int num = s.size();

    while(num!=0){
        rtn = to_string(num%2) + rtn;
        num /= 2;
    }
    
    return rtn;
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    while(s!="1"){
        string tmp;
        answer[0]++;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='1') 
                tmp+=s[i];
            else 
                answer[1]++;
        }
        s = trans_binary(tmp);
        cout<<s<<'\n';
    }

    return answer;
}

int main(void){

    vector<int> v = solution("110010101001");

    cout<<v[0]<<' '<<v[1]<<'\n';

    return 0;
}