#include <bits/stdc++.h>

using namespace std;

int count_one(int n) {
    string n_two;
    int cnt=0;

    while(n>0){
        n_two = to_string((n%2)) + n_two;
        n /= 2;
    }

    for(int i=0; i<n_two.length(); i++)
        if(n_two[i]=='1')
            cnt++;

    return cnt;
}
int solution(int n) {
    int answer = 0;
    int cur_cnt= count_one(n);

    while(true){
        if(count_one(++n) == cur_cnt){
            answer=n;
            break;
        }
    }

    return answer;
}

int main(void){

    cout<<solution(78)<<'\n';

    return 0;
}