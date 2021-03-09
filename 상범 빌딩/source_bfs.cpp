#include <bits/stdc++.h>

using namespace std;

int L,R,C;
string building[30][30];
int visited[30][30][30];
int start[3];
int result;

int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,-1,1};

int bfs(){

    queue<pair<pair<int,int>, pair<int,int> > > q;

    q.push(make_pair(make_pair(start[0], start[1]), make_pair(start[2], 0)));

    visited[start[0]][start[1]][start[2]]=1;

    while(!q.empty()){

        int x = q.front().first.second;
        int y = q.front().second.first;
        int z = q.front().first.first;
        int cnt = q.front().second.second;
        //cout<<z<<' '<<x<<' '<<y<<' '<<cnt<<'\n';
        q.pop();

        if(building[z][x][y]=='E'){
            return cnt;
        }
            

        for(int i=0; i<6; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nz=z+dz[i];

            if (nx>=0 && nx<R && ny>=0 && ny<C && nz>=0 && nz<L)
                if(!visited[nz][nx][ny]&& (building[nz][nx][ny]=='.' || building[nz][nx][ny]=='E')){
                    visited[nz][nx][ny]=1;
                    q.push(make_pair(make_pair(nz,nx),make_pair(ny, cnt+1)));
                }     
        }
    }

    return -1;
}

void init(){
    result=0;
    for(int i=0; i<30; i++)
        for(int j=0; j<30; j++){
            memset(visited[i][j], 0, sizeof(int)*30);
            building[i][j].clear();
        }
}

int main(void){

    while(true){
        cin>>L>>R>>C;

        if(!L && !R && !C)
            break;
            
        init();

        for(int floor=0; floor<L; floor++){
            for(int row=0; row<R; row++){
                cin>>building[floor][row];

                for(int i=0; i<building[floor][row].length(); i++){
                    if(building[floor][row][i]=='S'){
                        start[0]=floor;
                        start[1]=row;
                        start[2]=i;
                    }
                }
            }
        }
        result=bfs();

        if(result==-1)
            cout<<"Trapped!\n";
        else
            cout<<"Escaped in "<<result<<" minute(s).\n";
    }

    return 0;
}