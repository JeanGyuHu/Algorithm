#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b){
    return a+b>b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str_nums;

    for(int num : numbers) 
        str_nums.push_back(to_string(num));

    sort(str_nums.begin(), str_nums.end(), comp);

    if(str_nums[0]=="0") return "0";

    for(string num : str_nums)
        answer+=num;

    return answer;
}

int main(void){
    vector<int> v;

    v.push_back(3);
    v.push_back(30);
    v.push_back(34);
    v.push_back(5);
    v.push_back(9);

    cout<<solution(v)<<'\n';

    return 0;
}