#include <bits/stdc++.h>

using namespace std;

int result;

void dfs(vector<int> numbers, int target, int sum, int cnt) {
        
    if(cnt==numbers.size()){
        if(sum==target){
            result++;
        }
        return;
    }
     
    dfs(numbers, target, sum+numbers[cnt], cnt+1);
    dfs(numbers, target, sum-numbers[cnt], cnt+1);
}

int solution(vector<int> numbers, int target) {

    dfs(numbers, target, 0, 0);

    return result;
}

int main(void){

    vector<int> v;

    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);

    

    cout<<solution(v, 3)<<'\n';

    return 0;
}