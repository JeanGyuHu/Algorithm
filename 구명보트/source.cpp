#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 1;
    int sum=0;
    int cnt=0;
    int greatest=0;
    int smallest=people.size()-1;
    int visited[50000]={0,};
    
    sort(people.begin(), people.end(), greater<int>());

    while(cnt!=people.size()){
        if(sum+people[greatest]<=limit){
            visited[greatest]++;
            sum+=people[greatest++];
            cnt++;
        }
        else if(sum+people[smallest]<=limit){
            visited[smallest]++;
            sum+=people[smallest--];
            cnt++;
        }
        else{
            sum=0;
            answer++;
        }
    }

    return answer;
}

int main(void){

    vector<int> v;

    v.push_back(70);
    v.push_back(50);
    v.push_back(80);
    v.push_back(50);

    cout<<solution(v,100)<<'\n';

    return 0;
}