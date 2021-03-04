#include <bits/stdc++.h>

using namespace std;

int v,e;
int indegree[100001];
vector<int> graph[100001];

void topology_sort(){
    vector<int> result;
    queue<int> q;

    for(int i=1;i<=v;i++)
        if(indegree[i]==0) q.push(i);

    while(!q.empty()){
        int now = q.front();
        q.pop();

        result.push_back(now);

        for(int i=0; i<graph[now].size(); i++){
            indegree[graph[now][i]]--;

            if(indegree[graph[now][i]]==0)
                q.push(graph[now][i]);
        }
    }

    for(int i=0; i<v; i++)
        cout<<result[i]<<' ';
}

int main(void){

    cin>>v>>e;

    for(int i=0; i<v;i++){
        int a,b;
        cin>>a>>b;

        graph[a].push_back(b);
        indegree[b]++;
    }

    topology_sort();
    
    return 0;
}

/*
7 8
1 2
1 5
2 3
2 6
3 4
4 7
5 6
6 4

*/