#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string make_upper(string s){
    for(int i=0; i<s.length(); i++){
        s[i]=toupper(s[i]);
    }
    return s;
}

bool check_str(string s){
    for(int i=0; i<s.length(); i++){
        if(s[i]<'A' || s[i]>'Z')
            return false;
    }    
    return true;
}

void split_str(vector<string> &v, string s){
    string tmp;
    
    for(int i=0; i<s.length()-1; i++){
        tmp = s.substr(i,2);
        if(check_str(tmp))
                v.push_back(tmp);
    }
}

int solution(string str1, string str2) {
    vector<string> v1,v2;
    int answer = 0;
    
    str1=make_upper(str1);
    str2=make_upper(str2);
    
    split_str(v1, str1);
    split_str(v2, str2);
    
    if(v1.size()==0 && v2.size()==0) return 65536;
    
    int freq=0;
    int total = v1.size()+v2.size();
    
    for(auto i=v1.begin(); i != v1.end(); i++){
        auto j = find(v2.begin(), v2.end(), *i);
        if(j!=v2.end()){
            freq++;
            v2.erase(j);
        }
    }
    if(freq==0) return 0;
    return (int)(((double)freq/(total-freq))*65536);
}

int main(void){

    cout<<solution("FRANCE", "french")<<'\n';

    return 0;
}