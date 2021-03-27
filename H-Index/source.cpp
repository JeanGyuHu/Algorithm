#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0, i;
    int size = citations.size();

    sort(citations.begin(), citations.end());

    for(i=0; i<citations.size(); i++){
        int cur = citations[size-i-1];
        if(cur<=i) return i;
    }

    if(i==size) return i;
    return 0;
}
    // for(int i=citations.size()-1; i>=0; i--){
    //     int cnt=0;

    //     for(int j=0; j<citations.size(); j++){
    //         if(i<=citations[j])
    //             cnt++;
    //     }
    //     if(cnt>=i  cnt>h_idx){
    //         h_idx=cnt;
    //     }
    // }
//}

int main(void){

    vector<int> v;

    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    v.push_back(13);

    cout<<solution(v)<<'\n';

    return 0;
}