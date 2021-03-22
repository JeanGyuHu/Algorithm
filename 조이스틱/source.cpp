#include <bits/stdc++.h>

using namespace std;

//대문자 26개
int solution(string name) {
    int answer = 0,i = 0;
    string str_answer(name.size(), 'A');

    while(true){
        
        str_answer[i]=name[i];
        answer += min('Z'+1 - name[i], name[i]-'A');

        if(str_answer==name) break;

        for(int m=1; m<name.size(); m++){
            if(name[(i+m)%name.size()] != str_answer[(i+m)%name.size()]){
                i= (i+m)%name.size();
                answer+=m;
                break;
            }

            if(name[(i+name.size()-m)%name.size()] != str_answer[(i+name.size()-m)%name.size()]){
                i = (i+name.size()-m)%name.size();
                answer+=m;
                break;
            }
        }
    }

    return answer;
}

void print(string name, int answer){
    int a= solution(name);
    cout<<a<<" ";
    if(answer==a) cout<<"정답"<<'\n';
    else cout<<"틀림"<<'\n';
}

int main(void){

    print("JEROEN", 56);
    print("JAN", 23);
    print("AABAAAAAAAB", 6);
    print("AAAAAAAA", 0);
    print("ABBBBAAAABAA", 14);
    print("ABAAAAAAABA", 6);
    print("AAB", 2);
    print("AABAAAAAAABBB", 12);
    print("ZZZ", 5);

    return 0;
}