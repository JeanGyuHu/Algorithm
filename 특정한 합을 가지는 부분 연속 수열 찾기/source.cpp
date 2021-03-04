#include <bits/stdc++.h>

using namespace std;

int n=5;    //배열 크기
int m=5;    //특정 합
int arr[]={1,2,3,2,5};

int main(void){

    int end=0, interval_sum=0, cnt=0;

    for(int start=0; start<n;start++){

        while(interval_sum<m && end<n){
            interval_sum+=arr[end];
            end++;
        }
        if(interval_sum==m)
            cnt++;
        interval_sum-=arr[start];
    }

    cout<<cnt<<'\n';

    return 0;
}