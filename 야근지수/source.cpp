#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> pq;
    long long answer = 0;
    
    for(int i : works) pq.push(i);
    
    while(n-->0){
        if(pq.top()>0){
            int cur = pq.top();
            pq.pop();
            pq.push(cur-1);
        }
    }
    
    while(!pq.empty()) {
        answer+=pq.top()*pq.top();
        pq.pop();
    }
    
    return answer;
}