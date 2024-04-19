#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;
queue<int> q;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    for(int it: priorities) {
        q.push(it);
        pq.push(it);
    }
    
    int pass_cnt = 0;
    int idx = location;
    while(true){
        if(q.front() == pq.top()){
            q.pop();
            pq.pop();
            pass_cnt++;
            if(idx == 0){
                answer = pass_cnt;
                break;
            }else idx--;            
        }else{
            if(idx == 0) idx = q.size()-1;
            else idx--;
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    return answer;
}