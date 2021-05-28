#include <bits/stdc++.h>

using namespace std;

int main(void){
    int height;

    cin>>height;

    for(int i=0; i<height; i++){
        for(int j=0; j<height-i;j++)
            cout<<' ';
        for(int k=0; k<2*i+1; k++)
            cout<<'*';
        cout<<'\n';
    }

    cout<<"\n\n";

    for(int i=height-1; i>=0; i--){
        for(int j=0; j<height-i; j++)
            cout<<' ';
        for(int k=0; k<2*i+1; k++)
            cout<<'*';
        cout<<'\n';
    }

    return 0;
}