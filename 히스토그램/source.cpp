#include <bits/stdc++.h>

using namespace std;
//완전 탐색 시간 초과

int N;
int histogram[100002];
stack<int> st;

int main(void){
    int max_area=0;
    int x;

    cin>>N;

    for(int i=1; i<=N; i++) cin>>histogram[i];
    
    st.push(0);

    for(int i=1; i<=N+1; i++){
        while(!st.empty() && histogram[st.top()]>histogram[i]){
            int check = st.top();
            st.pop();
            max_area = max(max_area, histogram[check]*(i-st.top()-1));
        }

        st.push(i);
    }

    cout<<max_area<<'\n';

    return 0;
}