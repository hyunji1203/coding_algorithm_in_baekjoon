#include <bits/stdc++.h>
using namespace std;

int target_idx = 100, match;
int visited[51];
string static_target;

void bfs(string str, vector<string> words){
    queue<pair<string, int>> q;
    q.push({str, 0});
    
    while(q.size()){
        string now_str = q.front().first;
        int now_cnt = q.front().second;
        q.pop();
        
        for(int i=0; i<words.size(); i++){
            if(words[i] == static_target) target_idx = i;
            
            if(visited[i]) continue;
            
            int match_cnt = 0;
            for(int j=0; j<words[i].size(); j++){
                if(now_str[j] == words[i][j]){
                    match_cnt++;
                }
            }
            if(match_cnt == match){
                visited[i] = now_cnt + 1;
                q.push({words[i], now_cnt + 1});
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    static_target = target;
    match = begin.size() - 1;
    
    bfs(begin, words);
    if(target_idx == 100) {
        answer = 0;
    }else{
        answer = visited[target_idx];
    }
    
    return answer;
}