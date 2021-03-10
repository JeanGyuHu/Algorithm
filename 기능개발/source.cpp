#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int idx=0;
    int count=0;

    while(idx<progresses.size()){
        count=0;
        for(int i=idx; i<progresses.size(); i++){
            progresses[i]+= speeds[i];
        }

        if(progresses[idx]>=100){
            count=1;
            for(int i=idx+1; i<progresses.size(); i++){
                if(progresses[i]<100)
                    break;
                else count++;
            }
            answer.push_back(count);
            idx+=count;
        }
    }

    return answer;
}

int main(void){

    vector<int> v1,v2,rtn;

    // v1.push_back(93);
    // v1.push_back(30);
    // v1.push_back(55);

    // v2.push_back(1);
    // v2.push_back(30);
    // v2.push_back(5);

    v1.push_back(95);
    v1.push_back(90);
    v1.push_back(99);
    v1.push_back(99);
    v1.push_back(80);
    v1.push_back(99);

    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(1);

    rtn = solution(v1, v2);

    for(int i=0; i<rtn.size(); i++){
        cout<<rtn[i]<<' ';
    }

    return 0;
}