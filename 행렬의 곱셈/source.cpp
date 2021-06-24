#include <bits/stdc++.h>

using namespace std;

/*
2 3 2        5 4 3       22 22 11
4 2 4        2 4 1       36 28 18
3 1 4        3 1 1       29 20 14

10 6 6
16 8 4
*/
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for(int i=0; i<arr1.size(); i++){
        vector<int> v;
        for(int j=0; j<arr2[0].size(); j++){
            int sum=0;
            for(int k=0; k<arr1[0].size(); k++){
                sum += arr1[i][k] * arr2[k][j];
            }
            v.push_back(sum);
        }
        answer.push_back(v);
    }

    return answer;
}

int main(void){



    return 0;
}