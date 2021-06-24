#include <bits/stdc++.h>

using namespace std;

int visited[200];
int N;
vector<vector<int> > com;

void bfs(int n){
    queue<int> q;
    
    for(int i=0; i<N; i++){
        if(com[n][i] && n!=i) {
            q.push(i);
            visited[i]=1;
        }
    }
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(int i=0; i<N; i++){
            if(com[now][i] && !visited[i] && now != i){
                q.push(i);   
                visited[i]=1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    N=n;
    com=computers;
    int answer = 0;
    
    for(int i=0; i<N; i++)
    {
        if(!visited[i]){
            bfs(i);
            answer++;
        }
    }
    return answer;
}