#include <bits/stdc++.h>

using namespace std;

bool comp(char s1, char s2){
    return s1>s2;
}

int solution(string numbers) {

    cout<<"=================\n";

    int answer = 0;
    int d[9999999]={0,};
    vector<int> n(10,0);

    cout<<"=================\n";
    sort(numbers.begin(), numbers.end(), comp);
    int max_num =stoi(numbers);
    cout<<"=================1\n";

    for(int i=2; i<=max_num; i++){
        if(!d[i]){
            int j=2;
            while(i*j<=max_num){
                d[i*j++]=1;
            }
        }
    }

    cout<<"=================2\n";
    for(int i=0; i<numbers.size(); i++)
        n[numbers[i]-'0']++;

    cout<<"=================3\n";
    for(int i=2; i<max_num; i++){
        if(d[i]!=0) continue;
        string tmp=to_string(i);
        
        vector<int> v = n;
        for(int j=0; j<tmp.size(); j++){
            if(v[tmp[j]-'0']==0) break;
            v[tmp[j]-'0']--;
            if(j==tmp.size()-1) answer++;
        }
    }

    return answer;
}

int main(void){

    solution("1127");

    return 0;
}