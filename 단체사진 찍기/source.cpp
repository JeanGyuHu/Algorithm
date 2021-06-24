#include <bits/stdc++.h>

using namespace std;

bool check_condition(char comp, int dis, int tmp){
    switch(comp){
        case '<':
            return dis > tmp;
        case '>':
            return dis < tmp;
        case '=':
            return dis == tmp;
    }
    return false;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    
    string kakao_friends="ACFJMNRT";
    do{
        bool flag=true;
        
        for(string str : data){
            char first = str[0];
            char second = str[2];
            char comp = str[3];
            int dis = str[4]-'0';


                int x = kakao_friends.find(first) - kakao_friends.find(second);
                int tmp_dis = abs(x)-1;
                if(check_condition(comp, dis, tmp_dis)) continue;
                else {
                    flag = false;
                    break;
                }
        }
        if(flag) answer++;
    } while(next_permutation(kakao_friends.begin(), kakao_friends.end()));
    
    return answer;
}