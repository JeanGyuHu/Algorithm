#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer=1;
    map<string, int> m;

    for(int i=0; i<clothes.size(); i++){
        m[clothes[i][1]] += 1;
    }

    for(auto iter = m.begin(); iter != m.end(); iter++)
        answer *= iter->second + 1;

    return answer-1;
}

int main(void){

    
    return 0;
}