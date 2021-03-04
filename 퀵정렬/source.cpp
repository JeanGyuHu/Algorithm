#include <bits/stdc++.h>

using namespace std;

int arr[10]={7,8,2,5,0,4,1,3,9,6};

void quick_sort(int start, int end){
    
    if(start>=end) return;

    int pivot = start;
    int left = start+1;
    int right = end;

    while(left<=right){
        while(left<=end&&arr[pivot]>=arr[left]) left++;
        while(right>start&&arr[pivot]<=arr[right]) right--;
        if(left>right) swap(arr[right], arr[pivot]);
        else swap(arr[right], arr[left]);        
    }

    quick_sort(start, right-1);
    quick_sort(right+1, end);
}

int main(void){

    quick_sort(0,9);

    for(int i = 0; i<10;i++)
        cout<<arr[i]<<' ';

    return 0;
}