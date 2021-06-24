#include <bits/stdc++.h>

using namespace std;

int parents[100];

bool compare(vector<int> a, vector<int> b){ return a[2]<b[2]; }

int find_parent(int x){
    if(x==parents[x])
        return x;
    else
        return parents[x]=find_parent(parents[x]);
}

void union_node(int a, int b){
    
    a=find_parent(a);
    b=find_parent(b);
    
    if(a<b)
        parents[b]=a;
    else
        parents[a]=b;
}

int solution(int n, vector<vector<int> > costs) {
    int answer=0;
    
    sort(costs.begin(), costs.end(), compare); 
    
    for(int i=0; i<n;i++) parents[i]=i;
    
    for(int i=0; i<costs.size(); i++){
        int a = costs[i][0];
        int b = costs[i][1];
        int cost = costs[i][2];
        
        if(find_parent(a) != find_parent(b)){
            union_node(a,b);
            answer += cost;
        }
    }
    
    return answer;
}

int main(void){
    
    vector<vector<int> > v;
    vector<int> v2;

    v2.push_back(0);
    v2.push_back(1);
    v2.push_back(1);

    v.push_back(v2);
    v2.clear();

    v2.push_back(0);
    v2.push_back(2);
    v2.push_back(2);

    v.push_back(v2);
    v2.clear();

    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(5);

    v.push_back(v2);
    v2.clear();

    v2.push_back(1);
    v2.push_back(3);
    v2.push_back(1);

    v.push_back(v2);
    v2.clear();

    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(8);

    v.push_back(v2);
    v2.clear();

    cout<<solution(4, v)<<'\n';

    return 0;
}