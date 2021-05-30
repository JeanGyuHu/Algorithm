#include <bits/stdc++.h>

using namespace std;

long long get_factorial(int n){
    if(n==1) return 1;
    return n*get_factorial(n-1);
}

void dfs(vector<int>& answer, vector<int>& arr, int n, long long k, long long facto){
    
    if(arr.size()==1) return;
    
    long long a = k / facto;
    long long b = k % facto;
    
    facto /= n;
    
    answer.push_back(arr[a]);
    arr.erase(arr.begin()+a);
    
    dfs(answer, arr, n-1, b, facto);
    
}
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> arr;
    
    for(int i=1; i<=n; i++) arr.push_back(i);
    
    dfs(answer, arr, n-1, k-1, get_factorial(n-1));
    answer.push_back(arr[0]);
    
    return answer;
}