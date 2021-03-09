#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    
    for (int i=0; i<prices.size()-1; i++){
        int cnt=0;
        for(int j=i+1; j<prices.size(); j++){
            if(prices[i] > prices[j])
                break;
            else
                cnt++;
        }
        if(!cnt)
            cnt++;
        answer.push_back(cnt);
    }
    answer.push_back(0);

    return answer;
}

int main(void){

    vector<int> prices;
    vector<int> ans;

    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(3);

    ans = solution(prices);

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<' ';
    cout<<'\n';

    return 0;
}