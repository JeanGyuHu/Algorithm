#include <bits/stdc++.h>

using namespace std;

int n,x;
vector<int> arr;

//tip
int countByRange(vector<int> &v, int left, int right){
    vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), right);
    vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), left);

    return rightIndex - leftIndex;
}

int binary_search(int start, int end){
    int result=0, cnt=0;

    if(start>=end)
        return -1;

    int mid = (start + end) / 2;

    if (arr[mid]==x){
    /*    while(arr[mid-cnt]==x) cnt++;
        result+=cnt;
        cnt = 0;
        while(arr[mid+cnt+1]==x)cnt++;
        result+=cnt;
    */

    result = countByRange(arr, arr[mid], arr[mid]);
    }
    else if(arr[mid]>x) result = binary_search(start, mid-1);
    else result = binary_search(mid+1, end);
        
    
    return result;
}


int main(void){

    cin>>n>>x;

    for(int i = 0 ; i < n ; i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }

    cout<<binary_search(0,n)<<endl;

    return 0;
}