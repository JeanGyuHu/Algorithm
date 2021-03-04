/* 
2부터 N까지의 숫자 중에서 소수 찾기

장점 : 매우 빠르다.
단점 : 모든 숫자들에 대해서 메모리를 할당해야 하므로 메모리를 많이 먹는다.
    ex) 10억까지의 소수
*/

#include <bits/stdc++.h>

using namespace std;

int n;
vector<bool> arr;

int main(void){

    cin>>n;
    
    arr.assign(n+1, true);

    for(int i=2; i<=sqrt(n); i++){
        if(arr[i]){
            int j=2;
            while(i*j<=n){
                arr[i*j++]=false;
            }
        }
    }

    for(int i=2; i<=n; i++){
        if(arr[i]) cout<<i<<' ';
    }

    return 0;
}