#include <bits/stdc++.h>
using namespace std;

int main(void){

    int x=1,y=1,N;
    string move;
    char moveTypes[4]={'R', 'L', 'U', 'D'};
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};

    cin >> N;

    cin.ignore();
    getline(cin, move);
    
    for(int i = 0;i<move.size();i++){
        int nx=-1, ny=-1;

        for(int j = 0 ; j<4;j++){
            if(move[i]==moveTypes[j]){
                nx = x+dx[j];
                ny = y+dy[j];
            }
        }
        if(nx<1||nx>N||ny<1||ny>N) continue;

        x = nx;
        y = ny;
    }

    cout<< x<< ' '<<y<<endl;

    return 0;
}