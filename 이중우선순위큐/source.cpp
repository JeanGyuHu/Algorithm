#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int> > pq2;
    int leng=0;
    
    for(string s : operations){
        
        if(!leng){
            while(!pq1.empty()) pq1.pop();
            while(!pq2.empty()) pq2.pop();
        }
        
        if(s[0]=='I'){
            int num = stoi(s.substr(2));
            
            pq1.push(num);
            pq2.push(num);
            
            leng++;
        }
        else{
            if(!leng) continue;
            if(s[2]=='1') pq1.pop();
            else if(s[2]=='-') pq2.pop();
            leng--;
        }
    }
    
    if(leng){
        answer[0]=pq1.top();
        answer[1]=pq2.top();
    }
    
    return answer;
}