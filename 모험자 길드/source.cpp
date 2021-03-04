#include <bits/stdc++.h>
 
 using namespace std;

vector<int> arr;

int main(void){

    int N;
    int count=0, result=0;

    cin>>N;

    for(int i =0;i<N;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    for(int i =0 ; i<N;i++){
        count++;
        if(count==arr[i]){
            result++;
            count=0;
        }
    }

    cout<<result<<endl;

    return 0;
}