#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int,int> > hw;
int best_option[1001];

bool compare(const pair<int, int> a, const pair<int, int> b){
    return a.first> b.first;
}
int solution(){

    int result=0;

    for (int i=0; i<N; i++){
        int deadline=hw[i].second;

        while(deadline>=1){
            if(!best_option[deadline]){
                best_option[deadline]=hw[i].first;
                break;
            }
            else deadline--;
        }
    }
    int cnt=1;

    while(cnt<=1000)
        result+= best_option[cnt++];

    return result;
}
int main(void){

    cin>>N;

    for(int i=0; i<N; i++){
        int a,b;
        cin>>a>>b;

        hw.push_back(make_pair(b,a));
    }

    sort(hw.begin(), hw.end(), compare);

    cout<<solution()<<'\n';

    return 0;
}