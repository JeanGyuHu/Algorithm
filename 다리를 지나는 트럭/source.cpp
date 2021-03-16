#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int total_weight=0;
    int each=0;
    queue<int> q;

    for(int i=0; i<truck_weights.size(); i++){
        each=truck_weights[i];

        while(true){
            if(q.empty()){
                q.push(each);
                total_weight+=each;
                answer++;
                break;
            }
            else if(q.size()== bridge_length){
                total_weight-=q.front();
                q.pop();
            }
            else{
                if(total_weight+each > weight){
                    q.push(0);
                    answer++;
                }
                else{
                    q.push(each);
                    total_weight+=each;
                    answer++;
                    break;
                }
            }
        }
    }
    answer+=bridge_length;

    return answer;
}

int main(void){

    vector<int> v;
    
    v.push_back(7);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    cout<<solution(2, 10, v)<<'\n';

    return 0;
}