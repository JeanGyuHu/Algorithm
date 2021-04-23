#include <bits/stdc++.h>

using namespace std;

/*

# : 아래로 한 칸
> : 오른쪽으로 한 칸
< : 왼쪽으로 한 칸
* : 처음 나온 경우는 아래로 한 칸, 두번째 나오면 그자리에 멈춤

*/

int solution(vector<string> v){

    int w = v[0].size(),h=v.size(), cnt=0, x=0, y=0;
    int answer=0;


    for(int i=0; i<w; i++){
        x=0; y=i,cnt=0; 
        while(cnt<2){
            if(x==h){
                answer++;
                break;
            }
            switch(v[x][y]){
                case '#':
                    x++;
                    break;
                case '>':
                    if(y==w-1)
                        break;
                    y++;
                    break;
                case '<':
                    if(y==0)
                        break;
                    y--;
                    break;
                case '*':
                    if(cnt++==0)
                        x++;
                    break;
            }
        }
    }

    return answer;
}

int main(void){

    vector<string> v;

    v.push_back("######");
    v.push_back(">#*###");
    v.push_back("####*#");
    v.push_back("#<#>>#");
    v.push_back(">#*#*<");

    cout<<solution(v)<<'\n';

    return 0;
}