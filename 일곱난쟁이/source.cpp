#include <bits/stdc++.h>

using namespace std;

int height[9];
int num[2];

void solution(int total){

    int row,col;

    sort(height, height+9);

    for(row=8; row>0; row--){
        for(col=row-1;col>=0;col--){
            if(total-(height[row]+height[col])==100){
                num[0]=row;
                num[1]=col;
                return;
            }
        }
    }
}

int main(void){

    int total=0;

    for(int i=0; i<9;i++){
        cin>>height[i];
        total+=height[i];
    }

    solution(total);
    cout<<'\n';
    for(int i=0;i<9;i++){
        if(i!=num[0] && i!=num[1]) cout<<height[i]<<'\n';
    }

    return 0;
}