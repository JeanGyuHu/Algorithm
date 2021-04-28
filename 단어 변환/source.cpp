#include <bits/stdc++.h>

using namespace std;

int answer=100;
string tar;
int checked[50];

void dfs(string begin, vector<string> &words, int result){
    
    if(tar == begin){
        answer = min(answer, result);
        return;
    }
    
    for(int i=0; i<words.size(); i++){
        int cnt=0;
        for(int j=0; j<words[i].size(); j++){
            if(words[i][j]!=begin[j])
                cnt++;
            if(cnt==2)
                break;
        }
        
        if(cnt==1 && !checked[i]){
            checked[i]=1;
            dfs(words[i], words, result+1);
            checked[i]=0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int ans=0;
    tar = target;
    
    if(find(words.begin(), words.end(), target)==words.end()){
        return 0;
    }
    else{
        dfs(begin, words, 0);   
    }
    ans=answer;
    return ans;
}