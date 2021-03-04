#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int graph[501][501];
int n,m;

int main(void){

    cin>>n>>m;

    for(int i=0; i<501;i++){
        fill(graph[i], graph[i]+501, INF);
    }

    for(int a = 1; a<=n; a++)
        for(int b=1; b<=n; b++)
            if(a==b) {
                graph[a][b]=0;
                break;
            }

    for(int i=0; i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b]=c;
    }

    for(int k=1; k<=n; k++){
        for(int a=1; a<=n; a++){
            for(int b=1; b<=n; b++){
                graph[a][b]= min(graph[a][b], graph[a][k]+graph[k][b]);
            }
        }
    }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            if(graph[i][j]==INF)
                cout<<"INFINITY"<<'\n';
            else
                cout<<graph[i][j]<<'\n';
        }

    return 0;
}