#include <bits/stdc++.h>

using namespace std;

class visited{
    public:
        bool u;
        bool d;
        bool r;
        bool l;

        visited(){
            u=false;
            d=false;
            r=false;
            l=false;
        }
};

int solution(string dirs) {
    int answer = 0;
    int x = 5, y = 5;

    visited xy[11][11];

    for(int i=0; i<dirs.size(); i++){
        switch(dirs[i]){
            case 'U':
                if(x==0) break;
                if(!xy[x][y].u && !xy[x-1][y].d){
                    xy[x][y].u=true;
                    xy[x-1][y].d=true;
                    answer++;
                }
                x--;
                break;
            case 'D':
                if(x==10) break;
                if(!xy[x][y].d && !xy[x+1][y].u){
                    xy[x][y].d=true;
                    xy[x+1][y].u=true;
                    answer++;
                }
                x++;
                break;
            case 'R':
                if(y==10) break;
                if(!xy[x][y].r && !xy[x][y+1].l){
                    xy[x][y].r=true;
                    xy[x][y+1].l=true;
                    answer++;
                }
                y++;
                break;
            case 'L':
                if(y==0) break;
                if(!xy[x][y].l && !xy[x][y-1].r){
                    xy[x][y].l=true;
                    xy[x][y-1].r=true;
                    answer++;
                }
                y--;
                break;
        
        }
    }

    return answer;
}

int main(void){



    return 0;
}