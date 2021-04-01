#include <bits/stdc++.h>

using namespace std;


vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum=brown+yellow;
    queue<int> q;

    q.push(3);

    while(true){
        int height = q.front();
        cout<<height<<'\n';
        q.pop();
        if(sum%height==0){
            cout<<sum<<' '<<height<<'\n';
            int width=sum/height;
            cout<<width<<'\n';
            if(((width-2) * (height-2)) == yellow){
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
        
        q.push(height+1);
    }

    return answer;
}

int main(void){

    vector<int> v;

    v = solution(24,24);

    cout<<v[0]<<' '<<v[1]<<'\n';

    return 0;
}