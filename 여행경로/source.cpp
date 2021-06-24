#include <bits/stdc++.h>

using namespace std;

int v_size;
int *visited;
vector<vector<string> > t;
vector<string> ans;

bool compare(vector<string> a, vector<string> b){
    if(a[1]==b[1])
        return a[0]<b[0];
    return a[1]<b[1];
}

void dfs(string str,int cnt,vector<string> temp){
    temp.push_back(str);
    
    if(cnt==v_size){
        if(ans.size()==0)
            ans = temp;
        return;
    }

    for(int i=0; i<v_size; i++){
        if(t[i][0]==str && visited[i]==0){
            visited[i]=1;
            dfs(t[i][1], cnt+1,temp);
            visited[i]=0;
        }
    }
    temp.pop_back();
}

vector<string> solution(vector<vector<string> > tickets) {
    
    v_size=tickets.size();
    visited = new int[v_size]();
    vector<string> temp;
    
    sort(tickets.begin(), tickets.end(), compare);
    
    t=tickets;
    
    dfs("ICN", 0,temp);
    
    return ans;
}