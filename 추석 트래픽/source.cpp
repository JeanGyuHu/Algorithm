#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int,int>> time_table;
    
    for(string str : lines){
        string h = str.substr(11,2);
        string m = str.substr(14,2);
        string s = str.substr(17,6);
        int spend = stod(str.substr(23,str.length()-24))*1000;
        int end_time = (stoi(h) * 3600 * 1000) + (stoi(m) * 60 * 1000) + (stod(s) * 1000);
        
        time_table.push_back({end_time-spend+1, end_time});
    }
    
    for(int i=0; i<time_table.size(); i++){
        int cnt=1;
        for(int j=i+1; j<time_table.size(); j++){
            if((time_table[i].first+1000 >= time_table[j].first) || (time_table[i].second+1000 > time_table[j].first)) cnt++;
        }
        answer = max(cnt,answer);
    }
    
    
    return answer;
}