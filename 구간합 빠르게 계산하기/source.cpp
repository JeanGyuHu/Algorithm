#include <bits/stdc++.h>

using namespace std;

int arr[] = {10,20,30,40,50};
int n=5;
int sum_arr[6];

int main(void){

    int sum=0;
    
    for(int i=0; i<n;i++){
        sum+=arr[i];
        sum_arr[i+1] = sum;
    }

    int left=3, right=4;
    
    cout<<sum_arr[right]-sum_arr[left-1]<<'\n';

    return 0;
}