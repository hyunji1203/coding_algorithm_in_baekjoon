#include <bits/stdc++.h>
using namespace std;

queue<int> progresses_q;
queue<int> speeds_q;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int time = 1;
    
    for(int it: progresses) progresses_q.push(it);
    for(int it: speeds) speeds_q.push(it);
    
    while(progresses_q.size()){
        int ret = 0;
        while(true){
            if(progresses_q.front() + (speeds_q.front() * time) >= 100){
                progresses_q.pop();
                speeds_q.pop();
                ret++;
            }else break;
        }
        time++;
        if(ret > 0) answer.push_back(ret);
    }
    
    return answer;
}