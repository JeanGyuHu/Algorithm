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

int dfs(string str,int cnt){

    if(cnt==v_size+1)
        return 1;

    for(int i=0; i<v_size; i++){
        if(t[i][0]==str && visited[i]==0){
            visited[i]=1;
            int result = dfs(t[i][1], cnt+1);

            if(result == 1){
                ans.push_back(str);
                return 1;
            }
                
            visited[i]=0;
        }
    }
    return 0;
}

vector<string> solution(vector<vector<string> > tickets) {
    
    v_size=tickets.size();
    visited = new int[v_size]();
    queue<string> q;
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end(), compare);
    
    t=tickets;
    
    for(int i=0; i<v_size; i++){
        if(tickets[i][0]=="ICN"){
            int r= dfs(tickets[i][1], 0);
            if(r==1) break;
        }
    }
    answer=ans;
    return answer;
}

int main(void){

    vector<vector<string> > v;
    vector<string> v2;

    v2.push_back("ICN");
    v2.push_back("A");

    v.push_back(v2);
    v2.clear();

    v2.push_back("A");
    v2.push_back("ICN");

    v.push_back(v2);
    v2.clear();

    v2.push_back("ICN");
    v2.push_back("A");

    v.push_back(v2);
    v2.clear();

    v2 = solution(v);

    for(string str : v2) cout<<str<<'\n';

    return 0;
}