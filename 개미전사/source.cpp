#include <bits/stdc++.h>

using namespace std;

int n, k[100],d[100];

int main(void){

    cin>>n;

    for(int i=0; i<n;i++){
        cin>>k[i];
    }

    d[0] = k[0];
    d[1] = max(d[0], k[1]);

    for(int i = 2; i<n; i++){
        d[i] = max(d[i-1], d[i-2]+k[i]);
    }

    cout<<d[n-1]<<endl;
    
    return 0;
}