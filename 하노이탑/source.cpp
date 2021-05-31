#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int> >& answer, int n, int from, int bypass, int to){
    
    if(n==1) answer.push_back({from, to});
    else{
        dfs(answer, n-1, from, to, bypass);
        answer.push_back({from, to});
        dfs(answer, n-1, bypass, from, to);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    dfs(answer, n, 1, 2, 3);
    
    return answer;
}