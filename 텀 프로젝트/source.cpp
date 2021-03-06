#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int t;
int n;
int choice[100001];
int visited[100001];
int checked[100001];
int result;

void solution(int x){
    
    visited[x]=1;
    int next = choice[x];

    if(!visited[next])
        solution(next);
    else{
            if(!checked[next]){
                for(int i=next; i!=x; i=choice[i])
                    result++;
                result++;
            }
        }
        checked[x]=1;
}

void init(){
    result=0;
    memset(choice, 0, sizeof(choice));
    memset(visited, 0, sizeof(visited));
    memset(checked, 0, sizeof(checked));
}

int main(void){

    cin>>t;

    for (int tc=0; tc<t; tc++){
        cin>>n;
        
        init();

        for(int i=1; i<=n; i++){
            cin>>choice[i];
        }

        for(int i=1; i<=n; i++){
            if(!visited[i])
                solution(i);
        }

        cout<<n-result<<'\n';
    }        

    return 0;
}