#include <bits/stdc++.h>

using namespace std;

int main(void){

    int n,m,num;
    vector<int> arr;

    cin>>n>>m;

    for(int i = 0; i<n;i++){
        cin>>num;
        arr.push_back(num);
    }

    int start = 0;
    int end = 1e9;
    int result = 0;

    while(start<=end){
        int total = 0;
        int mid = (start+end) /2;

        for(int i=0;i<n;i++){
            if(mid < arr[i]) total += arr[i]-mid;
        }

        if(total >= m){
            start = mid+1;
            result = mid;
        }
        else
            end = mid-1;
    }

    cout<<result<<endl;

    return 0;
}