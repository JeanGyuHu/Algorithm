#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for(int i=0; i<new_id.length(); i++) new_id[i] = tolower(new_id[i]);
    
    for(int i=0; i<new_id.length();){
        if((new_id[i]>='a'&&new_id[i]<='z') || (new_id[i]>='0' && new_id[i]<='9') || (new_id[i]=='-') || (new_id[i]=='_') || (new_id[i]=='.')){
            i++;
        }
        else
            new_id.erase(i,1);
    }
    
    for(int i=1; i<new_id.length();){
        if(new_id[i-1]=='.' && new_id[i]=='.')
            new_id.erase(i,1);
        else
            i++;
    }
    
    if(new_id[0]=='.')
        new_id.erase(0,1);
    if(new_id[new_id.length()-1]=='.')
        new_id.erase(new_id.length()-1,1);
    
    if(new_id.length()==0)
        new_id+='a';
    
    if(new_id.length()>=16){
        new_id=new_id.substr(0,15);
        if(new_id[new_id.length()-1]=='.')
            new_id.erase(new_id.length()-1,1);
    }
    
    if(new_id.length()<=2){
        char ch = new_id[new_id.length()-1];
        while(new_id.length()!=3)
            new_id+=ch;
    }
    
    answer=new_id;
    
    return answer;
}