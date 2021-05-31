#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int a = s/n;
    int b = s%n;
    
    if(n>s){
        answer.push_back(-1);
        return answer;
    }
    for(int i=0; i<n; i++) answer.push_back(a);
    for(int i=0; i<b ;i++) answer[i]++;
    
    sort(answer.begin(), answer.end());
    
    return answer;
}