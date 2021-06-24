#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b){ return b==0? a : gcd(b,a%b); }
long long lcm(long long a, long long b){ return (a / gcd(a,b)) * b; }

int solution(vector<int> arr) {
    int answer = 0;

    answer=lcm(arr[0], arr[1]);

    for(int i=2; i<arr.size(); i++)
        answer=lcm(answer, arr[i]);
    
    return answer;
}

int main(void){

    vector<int> v;

    v.push_back(2);
    v.push_back(6);
    v.push_back(8);
    v.push_back(14);

    cout<<solution(v)<<'\n';

    return 0;
}