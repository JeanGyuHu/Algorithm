#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int, int> > q;
    priority_queue<int> pq;

    for(int i=0; i<priorities.size(); i++){

        q.push(make_pair(priorities[i], i));
        pq.push(priorities[i]);
    }

    while(!q.empty()){
        int pri=q.front().first;
        int idx =q.front().second;

        q.pop();

        if(pri==pq.top()){
            pq.pop();
            answer++;
            if(idx==location)
                break;
        }
        else q.push(make_pair(pri, idx));
    }

    return answer;
}

int main(void){

    vector<int> v;

    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(9);
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(1);

    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);

    cout<<solution(v,2)<<'\n';

    return 0;
}