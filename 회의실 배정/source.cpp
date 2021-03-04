#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> > t;

bool compare(const pair<int, int>& a, const pair<int, int>& b){
    if(a.second == b.second)
        return a.first<b.first;
    else
        return a.second<b.second;
}

int solution(){
    int end_time=0;
    int cnt=1;

    sort(t.begin(), t.end(),compare);
    
    end_time=t[0].second;

    for(int i=1; i<n; i++){
        if(end_time<=t[i].first){
            end_time=t[i].second;
            cnt++;
        }
    }
    
    return cnt;
}

int main(void){

    cin>>n;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;

        t.push_back(make_pair(a,b));
    }

    cout<<solution()<<'\n';

    return 0;
}