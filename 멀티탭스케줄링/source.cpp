#include <bits/stdc++.h>

using namespace std;

int n,k;
int uses[100];
int tap[100];
int result=0;

void solution(){
    
    for(int i=0; i<k; i++){
        bool plug_check=false;

        for(int j=0; j<n; j++){
            if(tap[j]==0){
                tap[j]=uses[i];
                plug_check=true;
                break;
            }

            if(uses[i]==tap[j]){
                plug_check=true;
                break;
            }
        }

        if(plug_check)
            continue;

        int tap_idx=0, use_idx=0;

        for(int j=0; j<n; j++){
            int count=0;
            for(int l=i+1; l<k; l++){
                if(tap[j]==uses[l]){
                    break;
                }
                count++;
            }

            if(count>use_idx){
                use_idx=count;
                tap_idx=j;
            }
        }

        tap[tap_idx] = uses[i];
        result++;
    }
}

int main(void){

    cin>>n>>k;

    for(int i=0; i<k; i++){
        cin>>uses[i];
    }

    solution();

    cout<<result<<'\n';

    return 0;
}