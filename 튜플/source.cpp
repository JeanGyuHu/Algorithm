#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    bool res = a.size() < b.size();
    return res;
}
vector<vector<int> > str_split(string s){
    vector<vector<int> > v;
    vector<int> v2;
    string tmp;

    for(int i=1; i<s.length()-1; i++){
        if(s[i]=='{' || (s[i]==',' && s[i-1]=='}')){
            continue;
        }
        else if(s[i]=='}'){
            
            v2.push_back(stoi(tmp));
            v.push_back(v2);
            v2.clear();
            tmp.clear();
        }
        else if(s[i]>='0' && s[i]<='9'){
            tmp+=s[i];
        }
        else{
            v2.push_back(stoi(tmp));
            tmp.clear();
        }        
    }
    
    return v;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int> > v = str_split(s);

    sort(v.begin(), v.end(), compare);
    
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            if(find(answer.begin(), answer.end(), v[i][j])==answer.end()){
                answer.push_back(v[i][j]);
            }
            else{
                continue;
            }
        }
    }

    return answer;
}

int main(void){

    vector<int> v = solution("{{20,111},{111}}");

    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<' ';

    return 0;
}