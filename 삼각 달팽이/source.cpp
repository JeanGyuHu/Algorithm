#include <bits/stdc++.h>
#define DOWN 0
#define LEFT 1
#define UP 2

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    int mode=DOWN,x=0,y=0,cnt=1;
    int tower[1000][1000];

    memset(tower, 0 , sizeof(tower));
    
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(mode==DOWN){
                tower[x++][y]= cnt++;
            }
            else if(mode==LEFT){
                tower[x][y++]=cnt++;
            }
            else {
                tower[x--][y--]= cnt++;
            }
        }
        if(mode==DOWN){
            x--;
            y++;
            mode=LEFT;
        }
        else if(mode==LEFT){
            x--;
            y-=2;
            mode=UP;
        }
        else{
            x+=2;
            y++;
            mode=DOWN;
        }
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
            answer.push_back(tower[i][j]);
    
    return answer;
}

int main(void){
    vector<int> v;

    v = solution(5);

    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<' ';

    return 0;
}