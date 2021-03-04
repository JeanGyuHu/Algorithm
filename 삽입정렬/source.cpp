#include <bits/stdc++.h>

using namespace std;

int arr[10]={7,8,2,5,0,4,1,3,9,6};

void sort_func(){
    for(int i=1;i<10;i++){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1])
                swap(arr[j],arr[j-1]);
            else break;
        }
    }
}

int main(void){

    sort_func();

    for(int i = 0;i < 10; i++)
        cout<<arr[i]<<' '<<endl;

    return 0;
}