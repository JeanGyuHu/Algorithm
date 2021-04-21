#include <bits/stdc++.h>

using namespace std;

long long calculator(long long num1, long long num2, char oper){

    switch(oper){
        case '*':
            return num1 * num2;
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
    }
}

void split_expression(vector<char> &cates, vector<long long> &nums, vector<char> &opers, string expression){
    
    string tmp;

    for(char c : expression){
        if(c>='0' && c<='9')
            tmp+=c;
        else{
            nums.push_back(stoll(tmp));
            tmp.clear();
            if(find(cates.begin(), cates.end(), c)==cates.end())
                cates.push_back(c);
            opers.push_back(c);
        }
    }
    sort(cates.begin(), cates.end());
    nums.push_back(stoi(tmp));
}

long long solution(string expression) {
    long long answer = 0;

    vector<long long> nums;
    vector<char> opers;
    vector<char> cates;

    split_expression(cates, nums, opers, expression);    
 
    do {
        vector<long long> tmp_nums = nums;
        vector<char> tmp_opers = opers;

        for(int i=0; i<cates.size(); i++){
            for(int j=0; j<tmp_opers.size(); j++){
                if(cates[i] == tmp_opers[j]){
                    tmp_nums[j] = calculator(tmp_nums[j], tmp_nums[j+1], tmp_opers[j]);

                    tmp_nums.erase(tmp_nums.begin()+j+1);
                    tmp_opers.erase(tmp_opers.begin()+j);
                    j--;
                }
                    
            }
        }

        answer = max(answer, abs(tmp_nums[0]));

    }while(next_permutation(cates.begin(), cates.end()));


    return answer;
}

int main(void){

    cout<<solution("100-200*300-500+20")<<'\n';

    return 0;
}