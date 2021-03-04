#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m;
int graph[101][101];

int main(void){

    cin>>n>>m;

    for(int i=1; i<=101; i++)
        fill(graph[i], graph[i]+101, INF);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            if(i==j) {
                graph[i][j]=0;
                break;
            }
        }
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;

        graph[x][y]=1;
        graph[y][x]=1;
    }

    int x,k;

    cin>>x>>k;

    for(int k=1; k<=n; k++){ 
        for(int a=1; a<=n; a++){
            for(int b=1; b<=n; b++){
                graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b]);
            }
        }
    }

    cout<<'\n';

    for(int k=1; k<=n; k++){
        for(int a=1; a<=n; a++){
            cout<<graph[k][a]<<' ';
        }
        cout<<'\n';
    }

    cout<<graph[1][k]+graph[k][x]<<'\n';

    return 0;
}

/*

5 7
1 2
1 3
1 4
2 4
3 4
3 5
4 5
4 5

*/