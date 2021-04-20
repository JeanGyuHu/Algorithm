#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    vector<int> v;
    string answer = "", tmp;
    bool flag=true;

    for(int i=0; i<s.size(); i++){
        if(s[i]==' '){
            v.push_back(stoi(tmp));
            tmp.clear();
            flag = true;
            continue;
        }
        else
            tmp+=s[i];
    }

    v.push_back(stoi(tmp));

    sort(v.begin(), v.end());

    answer+=to_string(v.front());
    answer+=" ";
    answer+=to_string(v.back());

    return answer;
}

int main(void){

    cout<<solution("1 2 3 4")<<'\n';

    return 0;
}