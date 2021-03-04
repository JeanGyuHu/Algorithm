#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[100000], B[100000];

int main(void){

    cin>>N>>K;

    for(int i = 0 ;i<N;i++)
        cin>>A[i];


    for(int i=0; i<N; i++)
        cin>>B[i];

    sort(A, A+N);
    sort(B, B+N);

    for(int i=0;i<K;i++){
        swap(A[i],B[N-1-i]);
    }

    int sum =0;

    for(int i = 0 ; i < N;i++)
        sum+=A[i];

    cout<<sum<<endl;

    return 0;
}