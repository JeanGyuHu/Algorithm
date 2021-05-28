#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
    int size = s.length();
    
    for(;size>=2; size--){
        for(int i=0; i<=s.length()-size; i++){
            int front = i, end = i+size-1;
            bool flag = true;
            
            while(front<=end){
                if(s[front++]!=s[end--]){
                    flag = false;
                    break;
                }   
            }
            if(flag)
                return size;
        }
    }
    
    return 1;
}