#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> st;

    for(int i=0; i<prices.size(); i++){

        while(!st.empty() && prices[st.top()]> prices[i]){
            
            answer[st.top()] = i-st.top();

            st.pop();
        }
        st.push(i);
    }

    while(!st.empty()){
        answer[st.top()]= prices.size() - st.top()-1;
        st.pop();
    }

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