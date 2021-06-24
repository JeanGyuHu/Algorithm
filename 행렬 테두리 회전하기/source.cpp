#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> maps(rows, vector<int>(columns,0));
    vector<int> answer;
    
    int cnt=1;
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            maps[i][j]=cnt++;
    
    for(auto query : queries){
        int start_x = query[0]-1;
        int start_y = query[1]-1;
        int end_x = query[2]-1;
        int end_y = query[3]-1;
        int min_val = maps[start_x][start_y];
        vector<vector<int>> tmp=maps;
        
        for(int i=start_y; i<end_y; i++){
            maps[start_x][i+1] = tmp[start_x][i];
            min_val = min(min_val, tmp[start_x][i]);
        }
        
        for(int i=start_x; i<end_x; i++){
            maps[i+1][end_y] = tmp[i][end_y];
            min_val = min(min_val, tmp[i][end_y]);
        }
        
        for(int i=end_y; i>start_y; i--){
            maps[end_x][i-1] = tmp[end_x][i];
            min_val = min(min_val, tmp[end_x][i]);
        }
        
        for(int i=end_x; i>start_x; i--){
            maps[i-1][start_y] = tmp[i][start_y];
            min_val = min(min_val, tmp[i][start_y]);
        }
        answer.push_back(min_val);
    }
        
    
    return answer;
}