#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0, min_time = 1, max_time = *max_element(times.begin(), times.end()) * n;
    long long cnt=0;

    while(min_time<=max_time){
        long long avg_time = (max_time+min_time)/2;
        
        for(auto t : times) cnt+=avg_time/t;
        
        if(cnt>=n){
            answer=avg_time;
            max_time=avg_time-1;
        }
        else
            min_time=avg_time+1;
        cnt=0;
    }
    return answer;
}