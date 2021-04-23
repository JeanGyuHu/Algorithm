#include <bits/stdc++.h>

using namespace std;

bool compare_seq(vector<int> v1, vector<int> v2){
    if(v1[2] == v2[2])
        return v1[1]<v2[1];

    return v1[2] < v2[2];
}

bool compare_time(vector<int> v1, vector<int> v2){
    return v1[1] < v2[1];
}

vector<int> solution(vector<vector<int> > v){
    vector<int> ans;
    vector<vector<int> > wait;

    bool onoff=true;
    int time=0, i=0;
    int start=0, end=0;

    sort(v.begin(), v.end(), compare_time);

    while(true){
        if(ans.size()==v.size())
            break;

        if(time==v[i][1]){
            wait.push_back(v[i]);
            i++;
        }

        sort(wait.begin(), wait.end(), compare_seq);
        
        if(end == time){
            onoff=true;
        }

        if(onoff){
            ans.push_back(wait[0][0]);
            wait.erase(wait.begin());
            start=time;
            end=time+wait[0][2];
            
            onoff=false;
        }

        time++;
    }

    return ans;
}

int main(void){
    vector<vector<int> > v;
    vector<int> v2;

    v2.push_back(1);
    v2.push_back(0);
    v2.push_back(5);

    v.push_back(v2);
    v2.clear();

    v2.push_back(2);
    v2.push_back(2);
    v2.push_back(2);

    v.push_back(v2);
    v2.clear();

    v2.push_back(3);
    v2.push_back(3);
    v2.push_back(1);

    v.push_back(v2);
    v2.clear();

    v2.push_back(4);
    v2.push_back(4);
    v2.push_back(1);

    v.push_back(v2);
    v2.clear();

    v2.push_back(5);
    v2.push_back(10);
    v2.push_back(2);

    v.push_back(v2);

    v2 = solution(v);

    for(int i : v2)
        cout<<i<<' ';
    return 0;
}