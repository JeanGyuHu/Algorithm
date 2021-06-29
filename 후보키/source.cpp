#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > sets;

void combination(int n){

    for(int i=1; i<=n; i++){
        vector<bool> v(n, false);
        fill(v.begin(), v.begin()+i, true);
        
        do{
            vector<int> tmp;
            
            for(int i=0; i<n; i++)
                if(v[i])
                    tmp.push_back(i);
        
            sets.push_back(tmp);
        }while(prev_permutation(v.begin(),v.end()));
    }
}

bool check_candidate(vector<vector<string> >& relation, int n){
    map<string,int> candidates;
    
    for(int i=0; i<relation.size(); i++){
        string tmp;
        for(int k=0; k<sets[n].size(); k++){
            tmp+=relation[i][sets[n][k]]+ " ";
        }
        if(candidates[tmp]) return false;
        candidates[tmp]++;
    }
    return true;
}

bool is_involved(int a,int b){

    int n = sets[a].size();
    vector<bool> checked(n, false);
    
    for(int i=0; i<n; i++)
        if(find(sets[b].begin(), sets[b].end(), sets[a][i])!=sets[b].end())
            checked[i]=true;

    bool rtn=true;
    
    for(bool x : checked)
        rtn = rtn && x;
    
    return rtn;
}

int solution(vector<vector<string> > relation) {
    int answer = 0;
    
    combination(relation[0].size());
    
    int total = sets.size();
    for(int i=0; i<total; i++){
        if(check_candidate(relation, i)){
            for(int j=i+1; j<total; j++){
                if(is_involved(i,j)){
                    sets.erase(sets.begin()+j,sets.begin()+j+1);
                    total--;
                    j--;
                }
            }
            answer++;
        } 
    }
    
    return answer;
}

int main(void){

    vector<vector<string> > v;
    vector<string> v2;

    v2.push_back("aa");
    v2.push_back("a");

    v.push_back(v2);
    v2.clear();

    v2.push_back("a");
    v2.push_back("aa");

    v.push_back(v2);
    v2.clear();
    
    v2.push_back("a");
    v2.push_back("a");

    v.push_back(v2);
    v2.clear();
    
    cout<<'\n'<<solution(v)<<'\n';

    return 0;
}