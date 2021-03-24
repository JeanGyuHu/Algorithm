#include <bits/stdc++.h>

using namespace std;

//4개가 
string solution(string number, int k) {
    string answer = "";
    int cur=-1;

    for(int i=0; i<number.size()-k; i++){
        int max_num=-1;
        for(int j=++cur; j<=i+k; j++){
            if(max_num < number[j]){
                cur=j;
                max_num=number[j];
            }
        }
        answer+=max_num;
    }
    return answer;
}

int main(void){

    cout<<solution("1924",2)<<'\n';
    cout<<solution("1231234",3)<<'\n';
    cout<<solution("4177252841",4)<<'\n';

    return 0;
}