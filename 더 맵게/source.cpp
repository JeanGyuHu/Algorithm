#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int> q;

    for(int i=0; i<scoville.size(); i++)
        q.push(-scoville[i]);
    
    
    while(-q.top()<K && q.size()>1){
        answer++;
        int fst = - q.top();
        q.pop();
        int snd = - q.top();
        q.pop();

        int new_menu = -(fst + (snd * 2));
    
        q.push(new_menu);
    }
    if(-q.top()<K)
        return -1;
    else
        return answer;
}

int main(void){

    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(9);
    v.push_back(10);
    v.push_back(12);

    cout<<solution(v, 7)<<'\n';

    return 0;
}