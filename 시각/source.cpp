#include <bits/stdc++.h>

using namespace std;

int main(void){

    int h, m, s;
    int N;
    int count=0;

    cin>>N;

    for(h=0;h<=N;h++){
        for(m=0;m<60;m++){
            for(s=0;s<60;s++){
                if(h/10==3||h%10==3||m/10==3||m%10==3||s/10==3||s%10==3)
                    count++;
            }
        }
    }

    cout<<count<<endl;

    return 0;
}