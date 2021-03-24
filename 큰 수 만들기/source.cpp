#include <bits/stdc++.h>

using namespace std;
/*
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
*/
string solution(string number, int k) {
    string answer = "";
    answer = number.substr(k); 
    for(int i = k-1;i >=0;i--){
        int j = 0;
        do{
            if(number[i] >= answer[j]){
                char temp = answer[j];
                answer[j] = number[i];
                number[i] = temp;
                j++;
            }else{
                break;
            }
        }while(1);
    }



    return answer;
}

/*
1, 9, 2, 4
1, 2, 9, 4

*/

int main(void){

    cout<<solution("1924",2)<<'\n';
    cout<<solution("1231234",3)<<'\n';
    cout<<solution("4177252841",4)<<'\n';

    return 0;
}