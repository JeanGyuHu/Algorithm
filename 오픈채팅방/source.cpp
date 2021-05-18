#include <bits/stdc++.h>

using namespace std;

vector<string> split_record(string record){
    vector<string> result;
    string tmp;
    
    for(char ch : record){
        if(ch!=' '){
            tmp+=ch;
        }
        else{
            result.push_back(tmp);
            tmp.clear();
        }
    }
    result.push_back(tmp);
    
    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> uid;
    map<string, string> unickname;
    
    for(int i=0; i<record.size(); i++){
        vector<string> sp_record = split_record(record[i]);
    
        if(sp_record[0]=="Enter"){
            answer.push_back("님이 들어왔습니다.");
            uid.push_back(sp_record[1]);
            unickname[sp_record[1]]=sp_record[2];
        }
        else if(sp_record[0]=="Leave"){
            answer.push_back("님이 나갔습니다.");
            uid.push_back(sp_record[1]);
        }
        else{
            unickname[sp_record[1]]=sp_record[2];
        }
    }
    
    for(int i=0; i<answer.size(); i++)
        answer[i] = unickname[uid[i]] + answer[i];
    
    return answer;
}