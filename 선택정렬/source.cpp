#include <bits/stdc++.h>

using namespace std;

int arr[10]={7,8,2,5,0,4,1,3,9,6};

void sort_func(){
    int min;

    for (int i=0;i<9;i++){
        min = i;
        for(int j =i+1;j<10;j++){
            if(arr[min]>arr[j])
                min = j;
        }
        swap(arr[min],arr[i]);
    }       
}

int main(void){

    sort_func();

    for(int i =0;i<10;i++)
        cout<<arr[i]<<' '<<endl;

    return 0;
}