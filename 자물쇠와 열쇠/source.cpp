#include <bits/stdc++.h>

using namespace std;

int key_size;
int lock_size;

void rotate_key(vector<vector<int>>& key){
    int size = key.size();
    vector<vector<int>> tmp=key;
    
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            key[j][size-i-1] = tmp[i][j];
}

bool is_match(vector<vector<int>>& board){
    for(int i=0; i<lock_size; i++)
        for(int j=0; j<lock_size; j++)
            if(board[key_size+i-1][key_size+j-1]!=1) return false;
                
    return true;
}

bool put_key(vector<vector<int>> key, vector<vector<int>> board, int x, int y){
    
    for(int i=0; i<key_size; i++)
        for(int j=0; j<key_size; j++)
            board[x+i][y+j]+=key[i][j];
    
    if(is_match(board)) return true;
    else return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    key_size = key.size();
    lock_size = lock.size();
    
    vector<vector<int>> board((key_size-1)*2+lock_size, vector<int>((key_size-1)*2+lock_size, 0));
    
    for(int i=0; i<lock_size; i++)
        for(int j=0; j<lock_size; j++)
            board[key_size+i-1][key_size+j-1] = lock[i][j];

    for(int i=0; i<4; i++){
        for(int j=0; j<board.size()-key_size+1; j++){
            for(int k=0; k<board.size()-key_size+1; k++){
                if(put_key(key, board,j,k))
                    return true;
            }
        }
        rotate_key(key);
    }
    
    return false;
}