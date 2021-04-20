#include <bits/stdc++.h>

using namespace std;

bool add_straight(int n, int first){
    int sum=0;

    while(1){
        if(sum==n)
            return true;
        if(sum>n)
            return false;
        sum+=first++;
    }
}

int solution(int n) {
    int answer = 0;

    for(int i=1; i<=n; i++)
        answer += add_straight(n, i);

    return answer;
}

int main(void){



    return 0;
}