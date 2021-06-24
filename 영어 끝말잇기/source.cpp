#include <bits/stdc++.h>

using namespace std;

vector<string> store[26];

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    bool flag = true;
    for(int i=0; i<words.size(); i++){
        int idx = words[i][0]-'a';
        if(i!=0 && words[i-1][words[i-1].size()-1] != words[i][0]){
            answer.push_back((i%n)+1);
            answer.push_back((i/n)+1);
            flag=false;
            break;
        }
        else if(find(store[idx].begin(), store[idx].end(), words[i])==store[idx].end()){
            store[idx].push_back(words[i]);
        }
        else{
            answer.push_back((i%n)+1);
            answer.push_back((i/n)+1);
            flag=false;
            break;
        }
    }

    if(flag){
        answer.push_back(0);
        answer.push_back(0);
    }
 
    return answer;
}

int main(void){

    
    return 0;
}