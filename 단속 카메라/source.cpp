#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    int nearest;
    
    sort(routes.begin(), routes.end());
    
    nearest = routes[0][1];
    
    for(int i=0 ;i<routes.size()-1; i++){
        if(nearest<routes[i+1][0]){
            answer++;
            nearest=routes[i+1][1];
        }
        nearest = min(nearest, routes[i+1][1]);
    }
    
    return answer;
}