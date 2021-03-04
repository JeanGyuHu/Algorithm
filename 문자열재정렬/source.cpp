#include <bits/stdc++.h>

using namespace std;

int main(void){
    
    string input;
    int idx=0;
    int result=0;

    cin>>input;
    sort(input.begin(), input.end());

    for(int i =0;i<input.size();i++){
        int ch = input[i]-'0';
        if(ch>=0&&ch<=9){
            idx = i;
            result+=ch;
        }
    }

    for(int i = idx+1;i<input.size();i++){
        cout<<input[i];
    }
    cout<<result<<endl;

    return 0;
}