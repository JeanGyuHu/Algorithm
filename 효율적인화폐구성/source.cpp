#include <bits/stdc++.h>

using namespace std;

int money[100];
int n,m;

int solution(){

    vector<int> d(m+1, 10001);
    d[0]=0;

    for(int i=0 ; i<n ; i++){
        for(int j=money[i]; j<=m; j++){
            if(d[j-money[i]]!=10001)
                d[j] = min(d[j-money[i]]+1, d[j]);
        }
    }
    if(d[m]==10001) return -1;
    else return d[m];
}

int main(void){

    cin>>n>>m;

    for(int i=0 ; i<n ; i++){
        cin>>money[i];
    }

    cout<<solution()<<endl;

    return 0;
}