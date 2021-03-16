#include <bits/stdc++.h>

using namespace std;

int visited[100][100];
int n,m;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void init(){
    for(int i=0; i<100; i++)
        memset(visited[i], 0, sizeof(int)*100);
    n=4; 
    m=6;
}

int bfs(int a, int b, vector<vector<int> > picture){
    int cnt=1;

    queue<pair<int, int> > q;

    q.push(make_pair(a,b));
    visited[a][b] = 1;

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;

        q.pop();

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n){
                if(!visited[nx][ny]&&picture[nx][ny]==picture[a][b]){
                    visited[nx][ny]=1;
                    q.push(make_pair(nx, ny));
                    cnt++;
                }
            }
        }
    }
    
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n,vector<vector<int> > picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int cnt;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(picture[i][j]!=0 && !visited[i][j]){
                cnt=bfs(i,j,picture);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, cnt);
            }
        }
        
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}

int main(void){

    vector<int> a(2);
    
    init();

    vector<vector<int> > picture;
    vector<int> v;
    
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);

    picture.push_back(v);
    v.clear();

    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(0);

    picture.push_back(v);
    v.clear();
        
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);

    picture.push_back(v);
    v.clear();
        
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);

    picture.push_back(v);
    v.clear();
        
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(3);

    picture.push_back(v);
    v.clear();

    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(3);

    picture.push_back(v);
    v.clear();

    a=solution(m,n,picture);
    
    cout<<a[0]<<' '<<a[1]<<'\n';

    return 0;
}


/*
[[1, 1, 1, 0], 
 [1, 2, 2, 0], 
 [1, 0, 0, 1], 
 [0, 0, 0, 1], 
 [0, 0, 0, 3], 
 [0, 0, 0, 3]]
*/