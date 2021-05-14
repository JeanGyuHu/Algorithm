#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l_cur=10, r_cur=12;
    char u_hand;
    
    if(hand=="right") u_hand='R';
    else u_hand='L';
    
    for(int i : numbers){
        if(i==1 || i==4 || i==7){
            l_cur=i;
            answer+='L';
        }
        else if(i==3 || i==6 || i==9){
            r_cur=i;
            answer+='R';
        }
        else{
            if (i==0) i=11;
            
            int l_abs = abs(l_cur-i);
            int r_abs = abs(r_cur-i);
            int l_dist = (l_abs%3) + (l_abs/3);
            int r_dist = (r_abs%3) + (r_abs/3);
            
            if(l_dist==r_dist){
                answer+=u_hand;
                if(u_hand=='R') r_cur=i;
                else l_cur=i;
            }
                
            else if(l_dist>r_dist){
                answer+='R';
                r_cur=i;
            }
                
            else{
                answer+='L';
                l_cur=i;
            }       
        }
    }
    
    return answer;
}