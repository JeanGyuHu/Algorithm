#include <bits/stdc++.h>

using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1, 1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    queue<pair<int, int> > q;

    q.push(make_pair(0,0));

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;

        q.pop();
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0 && nx<maps.size() && ny>=0 && ny < maps[0].size()){
                if(maps[nx][ny]==1){
                    maps[nx][ny]=maps[x][y]+1;
                    q.push(make_pair(nx,ny));
                }
                else if(maps[nx][ny] > maps[x][y]+1){
                    maps[nx][ny] = maps[nx][ny]+1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }

    if(maps[maps.size()-1][maps[0].size()-1]==1)
        answer=-1;
    else
        answer = maps[maps.size()-1][maps[0].size()-1];

    return answer;
}

int main(void){



    return 0;
}