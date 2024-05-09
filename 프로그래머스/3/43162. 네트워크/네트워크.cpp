#include<bits/stdc++.h>
using namespace std;

vector<int> adj[201];
int visited[201];

void go(int here){
    visited[here] = 1;
    
    for(int there: adj[here]){
        if(visited[there]) continue;
        go(there);
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    int idx = 0;
    for(vector<int> computer: computers){
        for(int i=0; i<computer.size(); i++){
            if(idx == i) continue;
            if(computer[i] == 0) continue;
            adj[idx].push_back(i);
        }
        idx++;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        go(i);
        answer++;
    }
    
    return answer;
}