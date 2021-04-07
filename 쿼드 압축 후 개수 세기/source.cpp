#include <bits/stdc++.h>

using namespace std;

int one_num, zero_num;
vector<vector<int>> v;

void dfs(int rs, int re, int cs, int ce){

    bool zero=true, one=true;

    for(int i=rs; i<re; i++){
        for(int j=cs; j<ce; j++){
            if(v[i][j]==0) one = false;
            if(v[i][j]==1) zero = false;
        }
    }

    if(zero == true){
        zero_num++;
        return;
    }
    if(one==true){
        one_num++;
        return;
    }
    
    dfs(rs, (rs+re)/2, cs, (cs+ce)/2);
    dfs((rs+re)/2, re, cs, (cs+ce)/2);
    dfs(rs, (rs+re)/2, (cs+ce)/2, ce);
    dfs((rs+re)/2, re, (cs+ce)/2, ce);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    v=arr;

    dfs(0,arr.size(),0, arr.size());

    answer.push_back(zero_num);
    answer.push_back(one_num);

    return answer;
}

int main(void){



    return 0;
}