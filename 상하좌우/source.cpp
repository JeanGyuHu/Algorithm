#include <bits/stdc++.h>

using namespace std;

int main(void){
//허진규 코드
    int N;
    int row=1, col=1;
    string input;

    cin>>N;
    cin.ignore();       //버퍼 비우기 문자열 전에 정수 받은 적 있으면 지워줘~

    getline(cin, input);

    for(int i =0;i< input.size(); i++) {
        switch(input[i]){
            case 'R':
                if(col<N)
                col++;
            break;
            case 'L':
                if(col>1)
                col--;
            break;
            case 'U':
                if(row>1)
                    row--;
            break;
            case 'D':
                if(row<N)
                    row++;
            break;
        }
    }

    cout<<row<<" "<<col<<endl;

    return 0;
}