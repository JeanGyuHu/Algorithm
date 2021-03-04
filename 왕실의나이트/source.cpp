#include <bits/stdc++.h>

using namespace std;

int main(void){

    int size = 8;
    string input;
    int x, y, count=0;

    int dx[8]={-2, -2, -1, 1, 2, 2, -1, 1};
    int dy[8]={-1, 1, 2, 2, -1, 1, -2, -2};

    getline(cin, input);

    x = input[0]-'a';
    y = input[1]-'1';

    for(int i = 0;i<8;i++){
        if(x+dx[i]<size&&x+dx[i]>0&&y+dy[i]<size&&y+dy[i]>0)
            count++;
    }

    cout<<count<<endl;
    
    return 0;
}