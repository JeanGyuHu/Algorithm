#include <bits/stdc++.h>
#define NON -100

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> genre_cnt;
    map<string, map<int, int> > music_cnt;
    vector<int> answer;
    
    for(int i=0; i<genres.size(); i++){
        genre_cnt[genres[i]]+=plays[i];
        music_cnt[genres[i]][i] = plays[i];
    }
    
    while(genre_cnt.size()>0){
        int max_num=0;
        string max_str;
        
        for(auto g : genre_cnt){
            if(g.second>max_num){
                max_num = g.second;
                max_str = g.first;
            }
        }
        
        for(int i=0; i<2; i++){
            int max_cnt=0, num = NON;
            for(auto m : music_cnt[max_str]){
                if(m.second > max_cnt){
                    max_cnt = m.second;
                    num = m.first;
                }
            }
            
            if(num == NON)
                break;
            else{
                answer.push_back(num);
                music_cnt[max_str].erase(num);
            }
        }
        genre_cnt.erase(max_str);
    }
    return answer;
}