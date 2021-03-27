#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());
    for(int i=0; i<phone_book.size()-1; i++)
        if(phone_book[i]==phone_book[i+1].substr(0,phone_book[i].size()))
            return false;

    return answer;
}

int main(void){

    vector<string> pb;

    pb.push_back("12");
    pb.push_back("123");
    pb.push_back("1235");
    pb.push_back("567");
    pb.push_back("88");

    cout<<solution(pb);

    return 0;
}