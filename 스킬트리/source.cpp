#include <bits/stdc++.h>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int rtn=-1;
    int pt=0;
    bool flag;

    for(int i=0; i<skill_trees.size(); i++){
        pt=0;
        flag=true;
        for(int j=0; j<skill_trees[i].size(); j++){
            rtn = skill.find(skill_trees[i][j]);

            if(rtn==-1)
                continue;

            else{
                if(rtn!=pt++){
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
            answer++;
    }

    return answer;
}

int main(void){

    vector<string> v;

    v.push_back("BACDE");
    v.push_back("CBADF");
    v.push_back("AECB");
    v.push_back("BDA");

    cout<<solution("CBD", v)<<'\n';

    return 0;
}