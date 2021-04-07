#include <bits/stdc++.h>

using namespace std;

vector<int> db[3][2][2][2];

vector<string> quary_split(string info){
    vector<string> rtn;
    string str;

    for(char c : info){
        if(c==' '){
            rtn.push_back(str);
            str.clear();
        }
        else
            str+=c;
    }
    rtn.push_back(str);

    return rtn;
}

vector<int> info_split(string info){
    vector<int> rtn;
    string str;
    int n;

    for(char c : info){
        if(c==' '){
            if(str=="cpp" || str=="backend" || str=="junior" || str=="chicken") n=0;
            else if(str=="python") n=2;
            else n=1;

            rtn.push_back(n);
            str.clear();
        }
        else
            str+=c;
    }
    rtn.push_back(stoi(str));

    return rtn;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for(string s : info){
        vector<int> v = info_split(s);
        db[v[0]][v[1]][v[2]][v[3]].push_back(v[4]);
    }

    for(int i=0; i<3; i++)
        for(int j=0; j<2; j++)
            for(int k=0; k<2; k++)
                for(int l=0; l<2; l++)
                    sort(db[i][j][k][l].begin(), db[i][j][k][l].end());

    for(string s : query){
        vector<string> v = quary_split(s);

        int ai, bi, aj, bj, ak, bk, al, bl;

        if(v[0]=="cpp") ai=bi=0;
        else if(v[0]=="java") ai=bi=1;
        else if(v[0]=="python") ai=bi=2;
        else {
            ai=0; bi=2;
        }

        if(v[2]=="backend") aj=bj=0;
        else if(v[2]=="frontend") aj=bj=1;
        else{
            aj=0; bj=1;
        }

        if(v[4]=="junior") ak=bk=0;
        else if(v[4]=="senior") ak=bk=1;
        else{
            ak=0; bk=1;
        }
        if(v[6]=="chicken") al=bl=0;
        else if(v[6]=="pizza") al=bl=1;
        else{
            al=0; bl=1;
        }

        int score = stoi(v[7]);

        int ans=0;
        for(int i=ai; i<=bi; i++){
            for(int j=aj; j<=bj; j++){
                for(int k=ak; k<=bk; k++){
                    for(int l=al; l<=bl; l++){
                        int n = db[i][j][k][l].size();
                        if(n==0) continue;

                        auto iter =lower_bound(db[i][j][k][l].begin(), db[i][j][k][l].end(), score);
                        if(iter == db[i][j][k][l].end()) continue;
                        ans+=n-(iter-db[i][j][k][l].begin());
                    }
                }
            }
        }
        answer.push_back(ans);
    }

    return answer;
}

int main(void){

    

    return 0;
}