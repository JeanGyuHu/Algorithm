#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words){
    vector<int> answer;
    map<string, int> h;

    h[words[0]]=1;

    for(int i=1; i<words.size(); i++){
        if(h[words[i]]||words[i-1][words[i-1].size()-1]!=words[i][0]){
            answer.push_back((i%n)+1);
            answer.push_back((i/n)+1);

            return answer;
        }
        else{
            h[words[i]]=1;
        }
    }
    answer.push_back(0);
    answer.push_back(0);

    return answer;
}

int main(void){


    return 0;
}