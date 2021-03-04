#include <bits/stdc++.h>

using namespace std;

int t;
int n,m;
int gold[20][20];
int dx[3] = {-1,0,1};        //오른 위, 오, 오른 아래
int dy[3] = {1,1,1};

int d[20][20];

int main(void){

    int result;
    
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n>>m;
        result=-1;
        

        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin>>gold[j][k];
                d[j][k]=gold[j][k];    
            }
        }
        
        for(int j=1;j<m;j++){
            for(int k=0;k<n;k++){
                //left-up
                int leftup;
                if(k==0) leftup = 0;
                else leftup = d[k-1][j-1];
                //left
                int left;
                left = d[k][j-1];
                //int left-down
                int leftdown;
                if(k==n-1) leftdown = 0;
                else leftdown = d[k+1][j-1];

                d[k][j] = d[k][j] + max(leftup, max(left, leftdown));
            }
        }

        for(int i=0; i<n; i++){
            if(result<d[i][m-1])
                result = d[i][m-1];
        }
        cout<<'\n'<<result<<'\n';

    }
    return 0;
}

/*
2                          
3 4
1 3 3 2 2 1 4 1 0 6 4 7
4 4
1 3 1 5 2 2 4 1 5 0 2 3 0 6 1 2
*/