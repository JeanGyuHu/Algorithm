#include <bits/stdc++.h>
#define MAX 1e9
using namespace std;

int L,R,C;
bool result=false;
int rt_cnt=MAX;
int start[3];

string building[30][30];
int visited[30][30][30];

int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,-1,1};
/*
    dfs로 풀 경우
    한번 갔던 경로에 대해서 가도 되는 길인가 아닌가에 대해서 visit
    처리가 굉장히 까다로움
    BFS로 바꿔서 풀이 도전!
*/
void dfs(int x, int y, int z,int cnt){

    if(building[z][x][y]=='E'){
        result=true;
        rt_cnt= min(cnt, rt_cnt);
        return;
    }

    visited[z][x][y]=1;

    for(int i=0; i<6; i++){
        
        int nx = x+dx[i];
        int ny = y+dy[i];
        int nz = z+dz[i];

        if(nx>=0 && nx<R && ny>=0 && ny<C && nz>=0 && nz<L)
            if(!visited[nz][nx][ny] && building[z][x][y]!='#'){
                dfs(nx,ny,nz,cnt+1);
                visited[nz][nx][ny]=0;
            }
     
    }
}

void init(){
    rt_cnt=MAX;
    result=false;
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

        dfs(start[0], start[1], start[2], 0);  

        if(result)
            cout<<"Escaped in "<<rt_cnt<<" minute(s).\n";
        else
            cout<<"Trapped!\n";
    }

    return 0;
}


/*
cin - 공백 없는 문자열 (enter x)
getline - 공백 있는 문자열 (enter o)
*/