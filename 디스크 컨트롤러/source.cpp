#include <bits/stdc++.h>

using namespace std;

struct cmp {
    bool operator()(vector<int> v1, vector<int> v2) {
        if(v1[1]==v2[1])
        return v1[0]<v2[0];
    return v1[1]>v2[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, time=0, idx=0, end=0;
    priority_queue<vector<int>, vector<vector<int> >, cmp> pq;
    
    sort(jobs.begin(), jobs.end());
    for(int i=0; i<jobs.size(); i++)

    while(idx!=jobs.size() || !pq.empty()){
        if(idx<jobs.size() && time>=jobs[idx][0]){
            pq.push(jobs[idx++]);
            continue;
        }
        
        if(!pq.empty()){
            time+=pq.top()[1];
            answer+= time-pq.top()[0];
            pq.pop();
        }
        else
            time=jobs[idx][0];
    }
    
    return answer/jobs.size();
}