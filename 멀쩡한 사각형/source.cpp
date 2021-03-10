#include <bits/stdc++.h>

using namespace std;

/* GCD 꿀 공식

int GCD(int a, int b){
    if(a==0) return b;
    return GCD(b%a, a);
}
*/
long long solution(int w,int h) {
    long long answer = (long long)w * (long long)h;
    long long gcd =0;

    for(int i = (w<h)? w : h; i>0; i--)
        if((w%i==0) && (h%i==0)){
            gcd = i;
            break;
        }

    answer = answer - (((w/gcd)+(h/gcd) -1) * gcd);

    return answer;
}

int main(void){

    cout<<solution(8,12)<<'\n';

    return 0;
}